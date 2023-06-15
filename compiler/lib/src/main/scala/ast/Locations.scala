package fpp.compiler.ast

import fpp.compiler.util.InternalError
import fpp.compiler.util.Location

/** Manage locations of AST nodes */
object Locations {

  private val map = new scala.collection.mutable.HashMap[AstNode.Id, Location]

  /**Used to check whether or not duplicate id maps to same location*/
  private val reverse_map = new scala.collection.mutable.HashMap[Location, AstNode.Id]


  /** Put a location into the map */
  def put(id: AstNode.Id, loc: Location): Option[Location] = {
    reverse_map.get(loc) match {
      case Some(duplicate_id: AstNode.Id) => 
        map.remove(duplicate_id)
        reverse_map.remove(loc)
        reverse_map.put(loc, id)
        map.put(id, loc)
      case None => 
        reverse_map.put(loc, id)
        map.put(id, loc)
    }
    
  }

  /** Get a location from the map. Throw an InternalError if the location is not there.*/
  def get(id: AstNode.Id): Location = getOpt(id) match {
    case Some(loc) => loc
    case _ => throw new InternalError(s"unknown location for AST node ${id}")
  }

  /** Get an optional location from the map */
  def getOpt(id: AstNode.Id): Option[Location] = map.get(id)

  def hashMapToListOfPairs(): List[(AstNode.Id, Location)] = map.toList


}
