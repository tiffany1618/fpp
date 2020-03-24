package fpp.compiler.transform

import fpp.compiler.ast._
import fpp.compiler.util._

/** Resolve include specifiers */
object ResolveSpecInclude extends AstTransformer {

  def default(in: In) = in

  final case class Data(visitedFiles: List[File])

  def transUnit(tuIn: Ast.TransUnit): Result.Result[Ast.TransUnit] = {
    for { result <- transUnit(Data(Nil), tuIn) }
    yield {
      val (_, tuOut) = result
      tuOut
    }
  }

  override def transUnit(dataIn: Data, tu: Ast.TransUnit): Result[Ast.TransUnit] = {
    for { result <- transformList(dataIn, tu.members, tuMember) } 
    yield {
      val (dataOut, members) = result
      (dataOut, Ast.TransUnit(members.flatten))
    }
  }
  
  private def moduleMember(in: In, member: Ast.ModuleMember): Result[List[Ast.ModuleMember]] = {
    def visitSpecInclude(
      in: In, 
      node: Ast.Annotated[AstNode[Ast.SpecInclude]]
    ): Result[List[Ast.ModuleMember]] = {
      System.out.println(s"visiting ${node}")
      val (pre, node1, post) = node
      val member = Ast.ModuleMember(pre, Ast.ModuleMember.SpecInclude(node1), post)
      Right(in, List(member))
    }
    val (pre, node, post) = member.node
    node match {
      case Ast.ModuleMember.SpecInclude(node1) => visitSpecInclude(in, (pre, node1, post))
      case _ => for { result <- matchModuleMember(in, member) } 
      yield {
        val (data, member) = result
        (data, List(member))
      }
    }
  }

  private def transformList[A,B](
    in: In,
    members: List[A],
    transform: (Data, A) => Result[B]
  ): Result[List[B]] = {
    members match {
      case Nil => Right(in, Nil)
      case head :: tail => for { 
        result1 <- transform(in, head) 
        result2 <- {
          val (out, _) = result1
          transformList(out, tail, transform)
        }
      }
      yield {
        val (_, members1) = result1
        val (out, members2) = result2
        (out, members1 :: members2)
      }
    }
  }

  private def tuMember(in: In, tum: Ast.TUMember) = moduleMember(in, tum)

  type In = Data

  type Out = Data

}