//command_handler.c

#include "functions.h"

//------------------------------------------------------------------
//handles the users input
void handleCommand(Node *new_node, Edge *new_edge, char *test_string)
{
  if (strcmp(test_string, "an") == 0)
  {
     addNode(new_node);
  }
  if (strcmp(test_string, "ae") == 0)
  {
    addEdge(new_edge, new_node);
  }
  if (strcmp(test_string, "se") == 0)
  {
    printEdge(new_node, new_edge);
  }
  if (strcmp(test_string, "sn") == 0)
  {
    printNodeList(*new_node);
  }
  if (strcmp(test_string, "dn") == 0)
  {
    deleteNode(new_node, new_edge);
  }
  if (strcmp(test_string, "de") == 0)
  {
    deleteEdge(new_edge);
  }
  if (strcmp(test_string, "sp") == 0)
  {
    printPath(new_node, new_edge);
  }
  if (strcmp(test_string,"q") == 0)
  {
  	free(new_edge);
  	new_edge = NULL;
  	free(new_node);
  	new_node = NULL;
    exit(EXIT_FAILURE);
  }
  if ((strcmp(test_string, "an")!=0)&&(strcmp(test_string, "ae")!=0)&&
      (strcmp(test_string, "se")!=0)&&(strcmp(test_string, "sn")!=0)&&
      (strcmp(test_string, "dn")!=0)&&(strcmp(test_string, "de")!=0)&&
      (strcmp(test_string, "q") !=0)&&(strcmp(test_string, "sp")!=0))
  {
    printf("Error: Invalid argument!\n");
  }
  free(test_string); 
  test_string = NULL;
}
//------------------------------------------------------------------
