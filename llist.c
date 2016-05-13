/////////////////////////////////////////////////////////////////
//
// Some functions that help build and manipulate linked lists.
// Each node must contain the following data:
//
//   int name (integer "name" of a city)
//   int x    (X coordinate)
//   int y    (Y coordinate)
//
// Adjust the code accordingly if your list nodes are different.
//
// File:    llist.c
// Author:  Erik Ratcliffe (erat@modal.us)
// Version: 0.1 
// Date:    May, 2016
//
/////////////////////////////////////////////////////////////////


#include "llist.h"   // All req'd C headers and function specs are
                     // included in this file.


// Create a new node for the linked list. Don't
// add the node in this function, just return it
// and let the calling function decide where to
// put it.
//
Node *newNode(int name, int x, int y, Node *next)
{
    Node *new_node; // new node...

    // Allocate memory for the new node and populate
    // it with content.
    //
    new_node       = malloc(sizeof(Node));
    new_node->name = name;
    new_node->x    = x;
    new_node->y    = y;
    new_node->next = next;

    return new_node;
}


// Insert a new node to the linked list.
//
void insertNode(Node *prev, Node *newNode)
{
    newNode->next = prev->next;
    prev->next = newNode;
}


// Delete a node from the linked list. Free its memory
// as well while you're at it.
//
void deleteNode(Node *prev, Node *delNode)
{
    prev->next = delNode->next;
    free(delNode);
    delNode = 0;
}


// Walk through a linked list and create a new list that has 
// all nodes in the first list but in reverse order.
//
Node *revList(Node *head)
{
    // Always keep track of the last node
    // added to the new linked list.
    Node *last = NULL;

    // While the list passed to this function still has nodes...
    //
    // Note: we don't need to specifically add nodes to the list 
    // because we're going in reverse. Each new node automatically 
    // gets the last added node as its "next" pointer, so each new 
    // node is attached automatically to the beginning of the linked 
    // list, like a tail that gets longer with each iteration.
    //
    while(head)
    {
        Node *new;
        int name = head->name;
        int x    = head->x;
        int y    = head->y;

        new = newNode(name, x, y, last);

        head = head->next;
        last = new;
    }

    return last;
}


// Build a linked list from an input file.
//
Node *fileToList(FILE *fp)
{
    Node *head;     // pointer to first node in linked list
    Node *tail;     // pointer to last node in linked list
    Node *nextNode; // pointer to next node in linked list
    char line[100]; // line read from input file
    char *name;     // name token
    char *x;        // X coordinate token
    char *y;        // Y coordinate token

    // Read each line of the input file, break up the content
    // into tokens, then build a new list node from the tokens.
    //
    if(fgets(line, sizeof(line), fp) != NULL)
    {
        // Assign first record to head node
        //
        name = strtok(line, " ");
        x    = strtok(NULL, " ");
        y    = strtok(NULL, " ");
        head = newNode(atoi(name), atoi(x), atoi(y), NULL);

        // One node means head and tail are the same.
        //
        tail = head;

        // Continue getting nodes for the list. Add to the END 
        // of the list.
        //
        while(fgets(line, sizeof(line), fp) != NULL)
        {
            name = strtok(line, " ");
            x    = strtok(NULL, " ");
            y    = strtok(NULL, " ");

            nextNode = newNode(atoi(name), atoi(x), atoi(y), NULL);
            tail->next = nextNode;
            tail = nextNode;
        }
    }

    return head;
}


// Copy a linked list. 
//
Node *copyList(Node *head)
{
    Node *newHead;  // pointer to first node in new linked list
    Node *tail;     // pointer to last node in new linked list
    Node *nextNode; // pointer to next node in new linked list
    int name;       // node name 
    int x;          // X coordinate
    int y;          // Y coordinate

    // Read each node in the existing list and
    // then build a new list node.
    //
    if(head)
    {
        // Assign first record to head node
        //
        name = head->name;
        x    = head->x;
        y    = head->y;
        newHead = newNode(name, x, y, NULL);

        // One node means head and tail are the same.
        //
        tail = newHead;

        // Continue getting nodes for the list. Add to the END 
        // of the list.
        //
        while(head->next)
        {
            head = head->next;

            name = head->name;
            x    = head->x;
            y    = head->y;

            nextNode = newNode(name, x, y, NULL);
            tail->next = nextNode;
            tail = nextNode;
        }
    }

    return newHead;
}


// Print the contents of the list
//
void printList(Node *head)
{
    int idx; // loop iterator

    // Step through the list and display each node's content
    //
    while(head)
    {
        printf("Node: %d (%d,%d)\n", head->name, head->x, head->y);
        head = head->next;
    }
}


// Free the memory from the list
//
void freeList(Node *head)
{
    int  idx;       // loop iterator
    Node *nextNode; // next node in list

    // Step through the list and free each node
    //
    while(head)
    {
        nextNode = head->next;
        free(head);
        head = 0;
        head = nextNode;
    }
}

