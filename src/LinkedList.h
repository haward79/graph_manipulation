#ifndef LinkedList_h

    #define LinkedList_h

    #include <stdlib.h>
    #include <stdio.h>

    typedef struct Node
    {
        int data;
        struct Node* next;
    } Node;

    // typedef struct _Node Node;

    Node* append(Node*, int);
    void insert(Node*, int);
    Node* trash(Node*, int);
    Node* indexOf(Node*, int);
    Node* search(Node*, int);
    int countSize(Node*);
    void checkNull(void*);
    Node* newNode();
    void print(Node*);
    void dealloc(Node*);
    Node* DFS(Node*, int, int, Node**);
    Node* BFS(Node*, Node*, int, Node**);

#endif

