OBJS = graph_structures.o \
       functions.o \
       command_handler.o \
       main.o

CC = gcc
LD = gcc
CC_FLAGS = -c
LD_FLAGS = -o
W_FLAG = -Wall
EXECUTABLE = routeplanner

routeplanner : $(OBJS)
	$(LD) $(W_FLAG) $(LD_FLAGS) $(EXECUTABLE) $(OBJS)

graph_structures.o : graph_structures.c \
                     graph_structures.h
	$(CC) $(CC_FLAGS) graph_structures.c

functions.o : functions.c \
              functions.h \
              graph_structures.h
	$(CC) $(W_FLAG) $(CC_FLAGS) functions.c

command_handler.o : command_handler.c \
                    command_handler.h \
                    functions.h
	$(CC) $(W_FLAG) $(CC_FLAGS) command_handler.c

main.o : main.c \
         command_handler.h
	$(CC) $(W_FLAG) $(CC_FLAGS) main.c

all : routeplanner

clean : 
	rm $(OBJS) $(EXECUTABLE)
