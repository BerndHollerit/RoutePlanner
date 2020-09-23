// graph_structures.c

#include "graph_structures.h"

//------------------------------------------------------------------
//creates an empty Node structure
void createEmptyNodeList(Node *new_node) //creates empty Node List
{

  new_node->current = NULL;
  new_node->previous = NULL;
  new_node->start = NULL;
}

//------------------------------------------------------------------
//creates an empty Edge structure
void createEmptyEdgeList(Edge *new_edge) //creates empty Edge List
{
  new_edge->current = NULL;
  new_edge->previous = NULL;
  new_edge->start = NULL;
}

//------------------------------------------------------------------
