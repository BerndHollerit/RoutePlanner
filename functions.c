// functions.c

#include "graph_structures.h"

//------------------------------------------------------------------
// figures out whether two entries are similar or not
int equal(char *entry1, char *entry2)
{
  if(strcmp(entry1, entry2) == 0)
    return(1);
  else
    return(0);
}

//------------------------------------------------------------------
// figures out whether the current element is out of the Node-list
int outOfNodeList(Node *new_node)                                   
{
  return (new_node->current == NULL);
}

//------------------------------------------------------------------
// figures out whether the current element is out of the Edge-list
int outOfEdgeList(Edge *new_edge)
{
  return (new_edge->current == NULL);
}

//------------------------------------------------------------------
// jumps one element in the Node-list forward
int proceedNodeList(Node *new_node)
{
  if (new_node->current == NULL)
  {
    return(0);
  }
  else
  {
    new_node->previous = new_node->current;
    new_node->current = new_node->current->next;
  }
  return(0);
}

//------------------------------------------------------------------
// jumps one element in the Edge-list forward
int proceedEdgeList(Edge *new_edge)
{
  if (new_edge->current == NULL)
  {
    return(0);
  }
  else
  {
    new_edge->previous = new_edge->current;
    new_edge->current = new_edge->current->next;
  }
  return(0);
}

//------------------------------------------------------------------
// sets the NodeElement "current" of the Node-list to the start 
// element
void setNodeToStart(Node *new_node)
{
  new_node->current = new_node->start;
  new_node->previous = NULL;
}

//------------------------------------------------------------------
// sets the EdgeElement "current" of the Edge-list to the start 
// element 
void setEdgeToStart(Edge *new_edge)
{
  new_edge->current = new_edge->start;
  new_edge->previous = NULL;
}

//------------------------------------------------------------------
// prints the Node-list starting with the first element
int printNodeList(Node new_node)
{
  setNodeToStart(&new_node);
  if (new_node.start == NULL)
  {
    return(0);
  }
  while (!outOfNodeList(&new_node))
  {
    printf("%s \n", new_node.current->name);
    proceedNodeList(&new_node);
  }
  return(0);
}

//------------------------------------------------------------------
// inserts a new NodeElement
void insertNode(Node *new_node,char *node_name)
{
  NodeElement *new_new_node = malloc((MAX_STR_LEN + 1)*(sizeof(NodeElement)));

  if ((new_new_node = (NodeElement*) malloc(sizeof(NodeElement))) == NULL)
  {
    exit(EXIT_FAILURE);
  }

  new_new_node->name = node_name;

  if (new_node->current == NULL)
  {
    new_new_node->next = NULL;
  }
  else
  {
    new_new_node->next = new_node->current;
  }

  if (new_node->start == new_node->current)
  {
    new_node->start = new_new_node;
    new_node->start->next = new_node->current;
  }
  else
  {
    new_node->previous->next = new_new_node;
  }
}

//------------------------------------------------------------------
// inserts a new EdgeElement
void insertEdge(Edge *new_edge, char *edge_name, char *source, char *destination)
{
  EdgeElement *new_new_edge = malloc((MAX_STR_LEN + 1)*sizeof(EdgeElement));
  if((new_new_edge = (EdgeElement*) malloc(sizeof(EdgeElement))) == NULL)
  {
    exit(EXIT_FAILURE);
  }

  new_new_edge->name = edge_name;
  new_new_edge->source = source;
  new_new_edge->destination = destination;

  if (new_edge->current == NULL)
  {
    new_new_edge->next = NULL;      
  }
  else
  {
    new_new_edge->next = new_edge->current;
  }

  if (new_edge->start == new_edge->current)
  {
    new_edge->start = new_new_edge;
    new_edge->start->next = new_edge->current;
  }
  else
  {
    new_edge->previous->next = new_new_edge;
  }
}

//------------------------------------------------------------------
// searches a NodeElement in the Node-list
void searchNode(Node *new_node, char *entry)
{
  setNodeToStart(new_node);
  while(!outOfNodeList(new_node) &&
        !equal(new_node->current->name, entry))
    proceedNodeList(new_node);
}

//------------------------------------------------------------------
// searches an EdgeElement in the Edge-list
void searchEdge(Edge *new_edge, char *entry)
{
  while(!outOfEdgeList(new_edge) &&
        !equal(new_edge->current->name, entry))
  {
    proceedEdgeList(new_edge);
  }
}

//------------------------------------------------------------------
// searches a source_node in the Edge-list
void searchEdgeSource(Edge *new_edge, char *entry)
{
  while(!outOfEdgeList(new_edge) &&
	(!equal(new_edge->current->source, entry)))
	{
    proceedEdgeList(new_edge);
  }
}

//------------------------------------------------------------------
// searches a destination_node in the Edge-list
void searchEdgeDestination(Edge *new_edge, char *entry)
{  
  while(!outOfEdgeList(new_edge) &&
        !equal(new_edge->current->destination, entry))
  {
    proceedEdgeList(new_edge);
  }
}

//------------------------------------------------------------------
// deletes an EdgeElement
int deleteEdgeElement(Edge *new_edge)
{
  if (new_edge->current == NULL)
  {
    return(0);
  }
  else
  {
    if(new_edge->previous == NULL)
	  new_edge->start = new_edge->current->next;
    else
	  new_edge->previous->next = new_edge->current->next;
    free(new_edge->current);
    new_edge->current = NULL;
  }
  return(0);
}

//------------------------------------------------------------------
// deletes a NodeElement
int deleteNodeElement(Node *new_node)
{
  if (new_node->current == NULL)
  {
    return(0);
  }
  else
  {
    if(new_node->previous == NULL)
	  new_node->start = new_node->current->next;
    else
	  new_node->previous->next = new_node->current->next;
    free(new_node->current);
    new_node->current = NULL;
  }
  return(0);
}

//------------------------------------------------------------------
// reads a line from the input prompt 
int readLine(char *str,unsigned max_strlen)
{
  char character_read = '\0';
  unsigned num_chars = 0;

  if ((max_strlen <= 0) || (str == NULL))
  return(ILLEGAL_ARGUMENTS);

  while((character_read = getchar()) != '\n')
  {
    *str++ = character_read;
    if (++num_chars >= max_strlen)
      break;
  }
  *str = '\0';
  return(num_chars);
}

//------------------------------------------------------------------
// reads a name of a node and adds it to the graph.
// figures out whether the node already exists
void addNode(Node *new_node)
{
  char *new_node_name = malloc((MAX_STR_LEN + 1)*sizeof(char));

  printf("Please enter the name of the node: ");
  readLine(new_node_name, MAX_STR_LEN);
  setNodeToStart(new_node);
  searchNode(new_node, new_node_name);

  if(!outOfNodeList(new_node))
  {
    printf("Error: Node already exists!\n");
    free(new_node_name);
    new_node_name = NULL;
  }
  else
  insertNode(new_node, new_node_name);
}

//------------------------------------------------------------------
// reads a name of a node and deletes it from the graph.
// ...figures out whether the node exists
// ...deletes all Edges related to the node
void deleteNode(Node *new_node, Edge *new_edge)
{
	unsigned char continues = 1;
  char *node_name = malloc((MAX_STR_LEN + 1)*sizeof(char));

  printf("Please enter the name of the node: ");
  setNodeToStart(new_node);
  readLine(node_name, MAX_STR_LEN);
  searchNode(new_node, node_name);
  while(continues > 0)
  {
    if (outOfNodeList(new_node))
    {
      printf("Error: Node does not exist! \n");
      free(node_name);
      node_name = NULL;
      continues = 0;
    }
    else
    deleteNodeElement(new_node);

    setEdgeToStart(new_edge);
    while((continues == 1) && (!outOfEdgeList(new_edge)))
    {
      setEdgeToStart(new_edge); 
      searchEdgeSource(new_edge, node_name);
      if (!outOfEdgeList(new_edge))
	    {
        deleteEdgeElement(new_edge);
	    }
    }
    setEdgeToStart(new_edge);
    while(continues == 1 && !outOfEdgeList(new_edge))
    {
      setEdgeToStart(new_edge);
      searchEdgeDestination(new_edge, node_name);
      if (!outOfEdgeList(new_edge))
	    {
        deleteEdgeElement(new_edge);
	    }
    }
  continues = 0;
  }
  continues = 1;
  free(node_name);
  node_name = NULL;
}

//-----------------------------------------------------------------
// reads the name of an edge and adds the edge to the graph
// figures out whether: the edge's name
//                      the edge's source node
//                      the edge's destination node
// exist or not and adds the edge to the graph
void addEdge(Edge *new_edge, Node *new_node)
{
	unsigned char continue_prog = 0;
  char *new_edge_name = malloc((MAX_STR_LEN + 1)*sizeof(char));
  char *source_name = malloc((MAX_STR_LEN + 1)*sizeof(char));
  char *destination_name = malloc((MAX_STR_LEN + 1)*sizeof(char));

  printf("Please enter the name of the source node: ");
  readLine(source_name, MAX_STR_LEN);
  printf("Please enter the name of the destination node: ");
  readLine(destination_name, MAX_STR_LEN);
  printf("Please enter the name of the edge: ");
  readLine(new_edge_name, MAX_STR_LEN);

  for(continue_prog = 1; continue_prog > 0; )
  {
    setNodeToStart(new_node);
    searchNode(new_node, source_name);
    if (outOfNodeList(new_node))
    {
      printf("Error: Invalid Arguments! \n");
      free(source_name);
      source_name = NULL;
	    continue_prog = 0;
    }

    setNodeToStart(new_node);
    searchNode(new_node, destination_name);
    if (continue_prog != 0 && outOfNodeList(new_node))
    {
      printf("Error: Invalid Arguments! \n");
      free(destination_name);
      destination_name = NULL;
	    continue_prog = 0;
    }

    setEdgeToStart(new_edge);
    searchEdge(new_edge, new_edge_name);
    if(continue_prog != 0 && !outOfEdgeList(new_edge))
    {
      printf("Error: Invalid Arguments! \n");
      free(new_edge_name);
      new_edge_name = NULL;
	    continue_prog = 0;
    }
    if (continue_prog == 1)
    {
      insertEdge(new_edge, new_edge_name, source_name, destination_name);
	    continue_prog = 0;
    }
  }
  continue_prog = 1;
}

//------------------------------------------------------------------
// reads a name of an edge, figures out whether the name exists
// and deletes the Edge from the graph
void deleteEdge(Edge *new_edge)
{
	unsigned char continue_program = 0;
  char *edge_name = malloc((MAX_STR_LEN + 1)*sizeof(char));
  char *source_name = malloc((MAX_STR_LEN + 1)*sizeof(char));
  char *destination_name = malloc((MAX_STR_LEN + 1)*sizeof(char));

  printf("Please enter the name of the source node: ");
  readLine(source_name, MAX_STR_LEN);
  printf("Please enter the name of the destination node: ");
  readLine(destination_name, MAX_STR_LEN);
  printf("Please enter the name of the edge name: ");
  readLine(edge_name, MAX_STR_LEN);

  while(continue_program > 0)
  {
    setEdgeToStart(new_edge);
    searchEdge(new_edge, edge_name);
    if (outOfEdgeList(new_edge))
    {
      printf("Error: Edge does not exist! \n");
      free(edge_name);
      edge_name = NULL;
	    continue_program = 0;
    }
    if (continue_program != 0 &&!outOfEdgeList(new_edge)&&
       !equal(new_edge->current->source, source_name))
	  {
      printf("Error: Edge does not exist! \n");
      free(source_name);
      source_name = NULL;
	    continue_program = 0;
	  }
    if (continue_program != 0 &&!outOfEdgeList(new_edge)&&
       !equal(new_edge->current->destination, destination_name))
	  {
      printf("Error: Edge does not exist! \n");
      free(destination_name);
      destination_name = NULL;
	    continue_program = 0;
	  }
    if (continue_program != 0 &&!outOfEdgeList(new_edge)
       &&equal(new_edge->current->source, source_name)
       &&equal(new_edge->current->destination, destination_name))
	  {
      deleteEdgeElement(new_edge);
      continue_program = 0;
	  }
    free(edge_name);
    edge_name = NULL;
    free(source_name);
    source_name = NULL;
    free(destination_name);
    destination_name = NULL;
  }
  continue_program = 1;
}

//------------------------------------------------------------------
// reads the name of a node and reads out all the edges related to it
void printEdge(Node *new_node, Edge *new_edge)
{
  char *node_name = malloc((MAX_STR_LEN + 1)*sizeof(char));

  printf("Please enter the name of the node: ");
  readLine(node_name, MAX_STR_LEN);

  searchNode(new_node, node_name);
  if (outOfNodeList(new_node))
  {
    printf("Node does not exist!\n");
    free(node_name);
    node_name = NULL;
  }
  else
  {
    setEdgeToStart(new_edge);
    while(!outOfEdgeList(new_edge))
    {
      searchEdgeSource(new_edge, node_name);
	    if (!outOfEdgeList(new_edge)&&!equal(new_edge->current->destination, node_name))
	    {
        printf("-> %s : %s \n", new_edge->current->destination
                              , new_edge->current->name);
	      proceedEdgeList(new_edge);
	    }
	    if (!outOfEdgeList(new_edge)&&equal(new_edge->current->source, node_name)
         &&equal(new_edge->current->destination, node_name))
	    {
	      printf("<-> %s : %s \n", node_name, new_edge->current->name);
	      proceedEdgeList(new_edge);
	    }
    }
    setEdgeToStart(new_edge);
    while(!outOfEdgeList(new_edge))
	  {
	    searchEdgeDestination(new_edge, node_name);
	    if (!outOfEdgeList(new_edge)&&!equal(new_edge->current->source, node_name))
	    {
	      printf("<- %s : %s \n", new_edge->current->source
		                           , new_edge->current->name);
        proceedEdgeList(new_edge);
	    }
	    if (!outOfEdgeList(new_edge)&&equal(new_edge->current->source, node_name))
	    proceedEdgeList(new_edge);
	  }
  }
  free(node_name);
  node_name = NULL;
}

//-------------------------------------------------------------------

int findPath(Edge *new_edge, char *source, char *destination)
{
  EdgeElement* help_pointer = new_edge->start;
  
  
  if((new_edge->current) && (strcmp(new_edge->current->source, source) == 0))
  {
  printf("%s",source);
  return(1);
  }
    setEdgeToStart(new_edge);

  while(!outOfEdgeList(new_edge))
  {
    if(strcmp(new_edge->current->destination, destination) == 0)
    {
      help_pointer = new_edge->current;
      if(findPath(new_edge, source, new_edge->current->source))
      {
        printf("->%s", help_pointer->destination);
	return(1); 
      }
      new_edge->current = help_pointer;
    }
    proceedEdgeList(new_edge);
  }
  return(0);
}

//------------------------------------------------------------------

int printPath(Node *new_node, Edge *new_edge)
{
  char *source = malloc((MAX_STR_LEN+1)*sizeof(char));
  char *destination = malloc((MAX_STR_LEN+1)*sizeof(char));
  
  printf("Please enter the name of the source node: ");
  readLine(source, MAX_STR_LEN);
  printf("Please enter the name of the destination node: ");
  readLine(destination, MAX_STR_LEN);
  searchNode(new_node, source);
  if(outOfNodeList(new_node))
  {
    printf("Error: Node does not exist!\n");
    return(0);
  }
  searchNode(new_node, destination);
  if(outOfNodeList(new_node))
  {
    printf("Error: Node does not exist!\n");
    return(0);
  }
  
  new_edge->current = NULL;
  if(findPath(new_edge, source, destination))printf("\n");
  else
    printf("Sorry, no path!\n");
  
  free(source);
  source = NULL;
  free(destination);
  destination = NULL;
  return(0);
}  
  
//------------------------------------------------------------------
