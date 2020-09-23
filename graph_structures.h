// graph_structures.h

//------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------------------
//Constants
#define MAX_STR_LEN 64
#define ILLEGAL_ARGUMENTS -1

//------------------------------------------------------------------
//NodeElement structure - represents a single node element in the 
//Node structure
struct NodeElement_
{
  char *name;
  struct NodeElement_ *next;
};

typedef struct NodeElement_ NodeElement;

//------------------------------------------------------------------
//Node structure - represents nodes in the graph
struct Node_
{
  NodeElement *current;
  NodeElement *previous;
  NodeElement *start;
};

typedef struct Node_ Node;

//------------------------------------------------------------------
//EdgeElement structure - represtents a single edge element in 
//the Edge structure.
struct EdgeElement_
{
  char *name;
  struct EdgeElement_ *next;
  char *source;
  char *destination;
};

typedef struct EdgeElement_ EdgeElement;

//------------------------------------------------------------------
//Edge structure - represents edges in the graph
struct Edge_
{
  EdgeElement *current;
  EdgeElement *previous;
  EdgeElement *start;
};

typedef struct Edge_ Edge;

//------------------------------------------------------------------
//functions
void createEmptyNodeList(Node *new_node);
void createEmptyEdgeList(Edge *new_edge);

//------------------------------------------------------------------
