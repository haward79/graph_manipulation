# What's this ?
This is a undirected graph manipulation program.

# How does it work ?
First, the program reads data about the graph(number of vertices and the edges).  
Second, this program print the topology of graph in linked list form.  
Finally, DFS(Depth First Search) and BFS(Breadth First Search) are performed.

# In details
## Form of graphs
Graphs are consist by vertices and edges. Data on each vertices are integers numbered from 0 to the number of vertices - 1.

## Available operations on Linked List
This program contains a pre-defined structure, *Node*. It is used for storing a node of linked list.

Following are available operations on Node for linked list :
1. **append**  
   Append a new node to the end of linked list.
2. **insert**  
   Insert a new node after specific node.
3. **trash**  
   Remove the node which contains the specific data in the linked list.  
   If the node doesn't exist, nothing operation done to the linked list.
4. **indexOf**  
   Get the node which contains the specific data.
5. **search**  
   Search and return the node which contains the specific data.
6. **countSize**  
   Return the size of the linked list.
7. **print**
   Print a linked list with its size.
8. **DFS**  
   Do DFS(Depth First Search) and return a linked list which contains the traversal result.
9. **BFS**  
   Do BFS(Breadth First Search) and return a linked list which contains the traversal result.

*For more information in details, please take the comments in the function definition for reference.*

## Sample input
Some sample inputs are put in 'sample' folder.
Each file contains a sample input.  
First line in file indicates the number of vertices in a graph. The following lines except last one indicate the vertices of edges. The last line, -1 -1, indicates the end of the edge inputting mode.

# Requirements
To compile and run this program, please install the following softwares:
1. C89 compiler
2. C runtime environment

# Installation and Run
Compile this program by using the following command in cmd, powershell, or terminal.

## Windows
    # Change work directory to the root of this repository.
    > cd [Root of this repo]

    # Compile codes in src folder. (Using gcc for example.)
    # Replace [program_name] with any filename you want.
    > gcc src/*.c -o [program_name].exe

    # Run program.
    > [program_name]

## Linux / Unix
    # Change work directory to the root of this repository.
    $ cd [Root of this repo]

    # Compile codes in src folder. (Using gcc for example.)
    # Replace [program_name] with any filename you want.
    $ gcc src/*.c -o [program_name]

    # Run program.
    $ ./[program_name]

# Copyright
This program is developed by haward79:  
[haward79's personal website](https://www.haward79.tw/)

Feel free to use or modify this program.  
2019/12/23

