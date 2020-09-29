package fpp.compiler.analysis

import fpp.compiler.ast._
import fpp.compiler.util._

/** Enter symbols into their scopes */
object EnterSymbols 
  extends Analyzer 
  with ComponentAnalyzer
  with ModuleAnalyzer
  with TopologyAnalyzer
{

  override def defAbsTypeAnnotatedNode(a: Analysis, aNode: Ast.Annotated[AstNode[Ast.DefAbsType]]) = {
    val (_, node, _) = aNode
    val data = node.getData
    val name = data.name
    val symbol = Symbol.AbsType(aNode)
    val nestedScope = a.nestedScope
    for (nestedScope <- nestedScope.put(NameGroup.Type)(name, symbol))
      yield updateMap(a, symbol).copy(nestedScope = nestedScope)
  }

  override def defArrayAnnotatedNode(a: Analysis, aNode: Ast.Annotated[AstNode[Ast.DefArray]]) = {
    val (_, node, _) = aNode
    val data = node.getData
    val name = data.name
    val symbol = Symbol.Array(aNode)
    val nestedScope = a.nestedScope
    for (nestedScope <- nestedScope.put(NameGroup.Type)(name, symbol))
      yield updateMap(a, symbol).copy(nestedScope = nestedScope)
  }

  override def defConstantAnnotatedNode(a: Analysis, aNode: Ast.Annotated[AstNode[Ast.DefConstant]]) = {
    val (_, node, _) = aNode
    val data = node.getData
    val name = data.name
    val symbol = Symbol.Constant(aNode)
    val nestedScope = a.nestedScope
    for (nestedScope <- nestedScope.put(NameGroup.Value)(name, symbol))
      yield updateMap(a, symbol).copy(nestedScope = nestedScope)
  }

  override def defEnumAnnotatedNode(a: Analysis, aNode: Ast.Annotated[AstNode[Ast.DefEnum]]) = {
    val (_, node, _) = aNode
    val data = node.getData
    val name = data.name
    val symbol = Symbol.Enum(aNode)
    val scopeNameList = a.scopeNameList
    for {
      nestedScope <- a.nestedScope.put(NameGroup.Type)(name, symbol)
      nestedScope <- nestedScope.put(NameGroup.Value)(name, symbol)
      a <- {
        val scope = Scope.empty
        val nestedScope1 = nestedScope.push(scope)
        val a1 = a.copy(nestedScope = nestedScope1, scopeNameList = name :: scopeNameList)
        visitList(a1, data.constants, defEnumConstantAnnotatedNode)
      }
    }
    yield {
      val scope = a.nestedScope.innerScope
      val newSymbolScopeMap = a.symbolScopeMap + (symbol -> scope)
      val a1 = a.copy(
        scopeNameList = scopeNameList,
        nestedScope = a.nestedScope.pop,
        symbolScopeMap = newSymbolScopeMap
      )
      updateMap(a1, symbol)
    }
  }

  override def defModuleAnnotatedNode(
    a: Analysis,
    aNode: Ast.Annotated[AstNode[Ast.DefModule]]
  ) = {
    val (_, node, _) = aNode
    val Ast.DefModule(name, members) = node.getData
    val oldModuleNameList = a.scopeNameList
    val newModuleNameList = name :: oldModuleNameList
    val a1 = a.copy(scopeNameList = newModuleNameList)
    val qualifiedName = Name.Qualified.fromIdentList(newModuleNameList.reverse)
    val symbol = Symbol.Module(qualifiedName)
    val (a2, scope) = a1.symbolScopeMap.get(symbol) match {
      case Some(scope) => (a1, scope)
      case None => {
        val scope = Scope.empty
        val nestedScope = Result.expectRight(a1.nestedScope.put(NameGroup.Value)(name, symbol))
        val nestedScope1 = Result.expectRight(nestedScope.put(NameGroup.Type)(name, symbol))
        val a = a1.copy(nestedScope = nestedScope1)
        (a, scope)
      }
    }
    val a3 = a2.copy(nestedScope = a2.nestedScope.push(scope))
    for (a <- visitList(a3, members, matchModuleMember))
    yield {
      val scope = a.nestedScope.innerScope
      val newSymbolScopeMap = a.symbolScopeMap + (symbol -> scope)
      val a1 = a.copy(
        scopeNameList = oldModuleNameList,
        nestedScope = a.nestedScope.pop,
        symbolScopeMap = newSymbolScopeMap
      )
      updateMap(a1, symbol)
    }
  }

  override def defPortAnnotatedNode(a: Analysis, aNode: Ast.Annotated[AstNode[Ast.DefPort]]) = {
    val (_, node, _) = aNode
    val data = node.getData
    val name = data.name
    val symbol = Symbol.Port(aNode)
    val nestedScope = a.nestedScope
    for (nestedScope <- nestedScope.put(NameGroup.Port)(name, symbol))
      yield updateMap(a, symbol).copy(nestedScope = nestedScope)
  }

  override def defStructAnnotatedNode(a: Analysis, aNode: Ast.Annotated[AstNode[Ast.DefStruct]]) = {
    val (_, node, _) = aNode
    val data = node.getData
    val name = data.name
    val symbol = Symbol.Struct(aNode)
    val nestedScope = a.nestedScope
    for (nestedScope <- nestedScope.put(NameGroup.Type)(name, symbol))
      yield updateMap(a, symbol).copy(nestedScope = nestedScope)
  }

  private def updateMap(a: Analysis, s: Symbol): Analysis = {
    val identList = (s.getUnqualifiedName :: a.scopeNameList).reverse
    val name = Name.Qualified.fromIdentList(identList)
    a.copy(qualifiedNameMap = a.qualifiedNameMap + (s -> name))
  }

  private def defEnumConstantAnnotatedNode(a: Analysis, aNode: Ast.Annotated[AstNode[Ast.DefEnumConstant]]) = {
    val (_, node, _) = aNode
    val data = node.getData
    val name = data.name
    val symbol = Symbol.EnumConstant(aNode)
    val nestedScope = a.nestedScope
    for (nestedScope <- nestedScope.put(NameGroup.Value)(name, symbol))
      yield updateMap(a, symbol).copy(nestedScope = nestedScope)
  }

}
