// functions.h

#include "graph_structures.h"

//------------------------------------------------------------------
// functions
int equal(char *entry1, char *entry2);
int outOfNodeList(Node *new_node);
int outOfEdgeList(Edge *new_edge);
int proceedNodeList(Node *new_node);
int proceedEdgeList(Edge *new_edge);
void setNodeToStart(Node *new_node);
void setEdgeToStart(Edge *new_edge);
int printNodeList(Node new_node);
void insertNode(Node *new_node, char *node_name);
void insertEdge(Edge *new_edge, char *edge_name, char *source, 
     char *destination);
void searchNode(Node *new_node, char *entry);
void searchEdgeSource(Edge *new_edge, char *entry);
void searchEdgeDestination(Edge *new_edge, char *entry);
int deleteEdgeElement(Edge *new_edge);
int deleteNodeElement(Node *new_node);
int readLine(char *str,unsigned max_strlen);
void addNode(Node *new_node);
void deleteNode(Node *new_node, Edge *new_edge);
void addEdge(Edge *new_edge, Node *new_node);
void deleteEdge(Edge *new_edge);
void printEdge(Node *new_node, Edge *new_edge);
int findPath(Edge *new_edge, char *source, char *destination);
int printPath(Node *new_node, Edge *new_edge);

//------------------------------------------------------------------
