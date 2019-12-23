#include "LinkedList.h"

Node* append(Node* head, int data)
{
    /*
     *  Add data to the end of the linked list.
     */

    Node* tmp = NULL;

    if(head == NULL)  // No node in this list.
    {
        head = newNode();
        
        head->data = data;
        head->next = NULL;
    }
    else
    {
        tmp = head;

        while(tmp->next != NULL)
            tmp = tmp->next;

        // Create new node.
        tmp->next = newNode();

        tmp = tmp->next;
        tmp->data = data;
        tmp->next = NULL;
    }

    return head;
}

void insert(Node* preNode, int data)
{
    /*
     *  Insert a node after preNode.
     */

    Node* tmp = NULL;

    if(preNode != NULL)
    {
        tmp = newNode();
        tmp->data = data;
        tmp->next = preNode->next;
        preNode->next = tmp;
    }
}

Node* trash(Node* head, int data)
{
    /*
     *  Remove node contains the data.
     *  If no node contains the data, linked list is not changed.
     */

    Node* tmp = NULL;
    Node* del = NULL;
    
    if(head != NULL)  // This list is not empty.
    {
        if(head->data == data)  // The data is at first node.
        {
            tmp = head;
            head = head->next;
            free(tmp);
        }
        else
        {
            tmp = head;

            while(tmp->next!=NULL && tmp->next->data!=data)
                tmp = tmp->next;

            // The data is found.
            if(tmp->next != NULL)
            {
                del = tmp->next;
                tmp->next = tmp->next->next;
                free(del);
            }
        }
    }

    return head;
}

Node* indexOf(Node* head, int index)
{
    /*
     *  Get the index node in the head.
     */

    int i=0, len=countSize(head);
    
    if(index>=0 && index<len)
    {
        for(i=0; i<index; ++i)
            head = head->next;

        return head;
    }
    else
        return NULL;
}

Node* search(Node* head, int data)
{
    /*
     *  Search the node contains the data and return it.
     */

    Node* tmp = NULL;

    if(head != NULL)  // This list is not empty.
    {
        if(head->data == data)  // The data is at the first node.
            return head;
        else
        {
            tmp = head;

            while(tmp->next!=NULL && tmp->next->data!=data)
                tmp = tmp->next;

            if(tmp->next != NULL)  // The data is found.
                return tmp->next;
            else
                return NULL;
        }
    }
    else
        return NULL;
}

int countSize(Node* head)
{
    /*
     *  Count the number of nodes in the list and return it.
     */

    int size = 0;
    Node* tmp = NULL;

    while(head != NULL)
    {
        head = head->next;
        ++size;
    }

    return size;
}

void checkNull(void* ptr)
{
    /*
     *  Check if ptr is NULL.
     *  NULL means malloc can not allocate memory due to heap memory is full.
     *  If NULL is detected, error message is printed and program terminate.
     */

    if(ptr == NULL)
    {
        printf("\n** Out of heap memory!\n** Program terminated.\n\n");
        exit(0);
    }
}

Node* newNode()
{
    /*
     *  Create new node and return it.
     *  Full heap memory check is included.
     */

    Node* tmp = NULL;

    tmp = (Node*)malloc(sizeof(Node));
    checkNull(tmp);

    return tmp;
}

void print(Node* head)
{
    int len = countSize(head);
    int i = 0;

    printf("Size: %d node(s) in the linked list.\n", len);

    if(len != 0)
    {
        for(i=0; i<len; ++i)
        {
            printf("[%d] %d\n", i, head->data);
            head = head->next;
        }
    }
    
    printf("\n");
}

void dealloc(Node* head)
{
    /*
     *  Release heap memory allocated by each node.
     */

    Node* tmp = NULL;

    while(head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

Node* DFS(Node* traversal, int data, int size, Node** head)
{
    /*
     *  Do depth first search traversal recursively by this function.
     *  The order of traversal is returned.
     *  
     *  # Parameter
     *  [traversal] A linked list to store traversal result.
     *  [data] Next data to search.
     *  [size] The number of vertices of head.
     *  [head] A linked list array to store topology of the graph.
     */

    int i=0, len=0;

    // The data is valid and it hasn't been visited.
    if(data>=0 && data<size && !search(traversal, data))
    {
        // Visit the data.
        traversal = append(traversal, data);

        // Go deeper.
        for(i=0, len=countSize(head[data]); i<len; ++i)
            DFS(traversal, indexOf(head[data], i)->data, size, head);
    }

    // Return visited order of data.
    return traversal;
}

Node* BFS(Node* traversal, Node* wait, int size, Node** head)
{
    /*
     *  Do breadth first search traversal recursively by this function.
     *  The order of traversal is returned.
     *  
     *  # Parameter
     *  [traversal] A linked list to store traversal result.
     *  [data] Next data to search.
     *  [wait] The queue waiting for traversal.
     *  [head] A linked list array to store topology of the graph.
     */

    int i=0, len=0;
    int data = 0;

    // There is at least one data in the waiting queue and the first data in queue is valid.
    if(countSize(wait)>0 && wait->data>=0 && wait->data<size)
    {
        // Visit current data.
        traversal = append(traversal, wait->data);

        // Add vertices which are adjacent to current data.
        for(i=0, len=countSize(head[wait->data]); i<len; ++i)
        {
            data = indexOf(head[wait->data], i)->data;

            if(!search(wait, data) && !search(traversal, data))
                wait = append(wait, data);
        }

        // Dequeue from waiting queue.
        wait = trash(wait, wait->data);

        // Go BFS.
        BFS(traversal, wait, size, head);
    }
    
    // Return visited order of data.
    return traversal;
}

