// main.c

////////////////////////////////////////////////////////////////////
// Filename: graph                                                //
// Version: 2.0                                                   //
// Authors: Hollerit, Pendl                                       //
// Description: The file is the source code for the second        //
// exercise. It defines a structure that represents a graph.      //
// All functions needed to edit the graph are included.           //
////////////////////////////////////////////////////////////////////

#include "command_handler.h"

//-------------------------------------------------------------------
// entry point for the programm
int main()
{
	unsigned char continue_programme = 0;
	Node *new_node = malloc((MAX_STR_LEN+1)*sizeof(Node));
	Edge *new_edge = malloc((MAX_STR_LEN+1)*sizeof(Edge));
  createEmptyNodeList(new_node);
  createEmptyEdgeList(new_edge);

  for(continue_programme = 1; continue_programme > 0; )
  {
    char *input =malloc((MAX_STR_LEN + 1)*sizeof(char));
    printf("> ");
    readLine(input, MAX_STR_LEN);
    handleCommand(new_node, new_edge, input);
  }
  free(new_edge);
  new_edge = NULL;
  free(new_node);
  new_node = NULL; 
  return(0);
}

//-------------------------------------------------------------------
