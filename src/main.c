#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#define kMaxSize 100

// Define boolean.
typedef enum {false, true} bool;

// Function prototype.
bool isValidVertex(int, int);

int main()
{
    int i = 0;
    int numVertex = 0;
    int vertex1=0, vertex2=0;
    int startVertex = -1;
    Node* head[kMaxSize];
    Node* traversal = NULL;
    Node* tmp = NULL;

    // Read number of vertices.
    while(numVertex<=0 || numVertex>kMaxSize)
    {
        printf("Please input the number of vertex: ");
        scanf("%d", &numVertex);
    }

    printf("There is %d vertex in the graph: from 0 to %d.\n", numVertex, numVertex-1);

    // Setup linked list for storing relations of vertices.
    for(i=0; i<numVertex; ++i)
        head[i] = NULL;

    // Read relation of vertex.
    while(true)
    {
        printf("\nInput -1 -1 to exit vertices input mode\n");
        printf("Please input two positive integer for adjacent vertices (tail to head): ");
        scanf("%d %d", &vertex1, &vertex2);

        if(isValidVertex(vertex1, numVertex) && isValidVertex(vertex2, numVertex))
        {
            head[vertex1] = append(head[vertex1], vertex2);
            head[vertex2] = append(head[vertex2], vertex1);
        }
        else
            break;
    }

    printf("\n");

    // Clear screen.
    system("clear");

    // Print adjacent list.
    printf("== Adjacent List ===========================\n");

    for(i=0; i<numVertex; ++i)
    {
        printf("[%d] -> []\n", i);
        print(head[i]);
    }

    // DFS.
    startVertex = -1;
    while(!isValidVertex(startVertex, numVertex))
    {
        printf("Please input a vertex number to start DFS: ");
        scanf("%d", &startVertex);
        printf("\n");
    }

    traversal = DFS(traversal, startVertex, numVertex, head);
    printf("== DFS =====================================\n");
    print(traversal);
    dealloc(traversal);
    traversal = NULL;

    // BFS.
    startVertex = -1;
    while(!isValidVertex(startVertex, numVertex))
    {
        printf("Please input a vertex number to start BFS: ");
        scanf("%d", &startVertex);
        printf("\n");
    }

    tmp = append(tmp, startVertex);
    traversal = BFS(traversal, tmp, numVertex, head);
    printf("== BFS =====================================\n");
    print(traversal);
    dealloc(traversal);
    traversal = NULL;

    // Release heap memory.
    for(i=0; i<numVertex; ++i)
        dealloc(head[i]);

    return 0;
}

// Function definition.
bool isValidVertex(int vertex, int numVertex)
{
    /*
     *  Check if vertex is valid number when there is numVertex vertices.
     */

    if(vertex>=0 && vertex<numVertex)
        return true;
    else
        return false;
}

