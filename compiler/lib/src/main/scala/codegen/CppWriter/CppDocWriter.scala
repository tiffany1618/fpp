package fpp.compiler.codegen

import java.time.Year

/** A C++ doc writer */
trait CppDocWriter extends CppDocVisitor with LineUtils {

  case class Input(
    /** The hpp file */
    hppFile: CppDoc.HppFile,
    /** The cpp file name */
    cppFileName: String,
    /** The list of enclosing class names, backwards. A class name may include :: */
    classNameList: List[String] = Nil,
  ) {

    def getEnclosingClassQualified = classNameList.reverse.mkString("::")
 
    def getEnclosingClassUnqualified = classNameList.head.split("::").reverse.head

  }

  def default(in: Input) = Nil

  def paramString(p: CppDoc.Function.Param): String

  def paramStringComma(p: CppDoc.Function.Param): String

  def visitCppDoc(cppDoc: CppDoc): Output

  final def writeParam(p: CppDoc.Function.Param) = line(paramString(p))

  final def writeParamComma(p: CppDoc.Function.Param) = line(paramStringComma(p))

  type Output = List[Line]

}

object CppDocWriter extends LineUtils {

  def bannerComment(comment: String) = {
    def banner =
      line("// ----------------------------------------------------------------------")
    (Line.blank :: banner :: commentBody(comment)) :+ banner
  }

  def comment(comment: String) = Line.blank :: commentBody(comment)

  def doxygenCommentOpt(commentOpt: Option[String]) = commentOpt match {
    case Some(comment) => doxygenComment(comment)
    case None => Line.blank :: Nil
  }
    
  def doxygenComment(comment: String) = 
    Line.blank ::lines(comment).map(Line.join(" ")(line("//!"))_)
    
  def commentBody(comment: String) = lines(comment).map(Line.join(" ")(line("//"))_)

  def leftAlignDirective(line: Line) =
    if (line.string.startsWith("#")) Line(line.string) else line

  def writeBanner(title: String) = lines(
    s"""|// ====================================================================== 
        |// \\title  $title
        |// \\author Generated by fpp-to-cpp
        |//
        |// \\copyright
        |// Copyright (C) ${Year.now.getValue} California Institute of Technology.
        |// ALL RIGHTS RESERVED.  United States Government Sponsorship
        |// acknowledged. Any commercial use must be negotiated with the Office
        |// of Technology Transfer at the California Institute of Technology.
        |// 
        |// This software may be subject to U.S. export control laws and
        |// regulations.  By accepting this document, the user agrees to comply
        |// with all U.S. export laws and regulations.  User has the
        |// responsibility to obtain export licenses, or other export authority
        |// as may be required before exporting such information to foreign
        |// countries or providing access to foreign persons.
        |// ======================================================================"""
  )

  def writeFunctionBody(body: List[Line]) = {
    val bodyLines = body.length match {
      case 0 => Line.blank :: Nil
      case _ => body.map(indentIn(_))
    }
    line("{") :: (bodyLines :+ line("}"))
  }

}
