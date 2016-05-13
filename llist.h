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
// File:    llist.h
// Author:  Erik Ratcliffe (erat@modal.us)
// Version: 0.1 
// Date:    May, 2016
//
/////////////////////////////////////////////////////////////////


#ifndef LLIST_H
#define LLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Linked list node for a TSP city:
//
//   name = city name (in this case, a number)
//   x    = X coordinate of the city
//   y    = Y coordinate of the city
//   next = pointer to the next node in the list
//
typedef struct node {
    int  name;
    int  x;
    int  y;
    struct node *next;
} Node;


// Create a new node for the linked list. Don't
// add the node in this function, just return it
// and let the calling function decide where to
// put it.
//
// Input: 
//   int name    Integer "name" for the data
//   int x       An integer X value
//   int y       An integer Y value
//   Node *next  Pointer to the next node in the list
//
// Output:
//   Returns a pointer to the new node.
//
Node *newNode(int name, int x, int y, Node *next);


// Insert a new node to the linked list.
//
// Input: 
//   Node *prev     Pointer to node that precedes this one
//   Node *newNode  Pointer to the new node
//
//   It is not necessary to pass the linked list to the function.
//   The pointer to the "previous" node is enough.
//
// Output:
//   None
//
void insertNode(Node *prev, Node *newNode);


// Delete a node from the linked list. Free its memory
// as well while you're at it.
//
// Input: 
//   Node *prev     Pointer to node that precedes this one
//   Node *delNode  Pointer to the node being deleted
//
//   It is not necessary to pass the linked list to the function.
//   The pointer to the "previous" node is enough.
//
// Output:
//   None
//
void deleteNode(Node *prev, Node *delNode);


// Walk through a linked list and create a new list that has 
// all nodes in the first list but in reverse order.
//
// Input: 
//   Node *head     Pointer to the head node in the existing list
//
// Output:
//   Node pointer to the new, reversed list.
//
Node *revList(Node *head);


// Build a linked list from an input file.
//
// Input: 
//   FILE *fp    Pointer to the input file
//
// Output:
//   Node pointer to the new list.
//
Node *fileToList(FILE *fp);


// Copy a linked list. 
//
// Input: 
//   Node *head     Pointer to the head node in the existing list
//
// Output:
//   Node pointer to the copied list.
//
Node *copyList(Node *head);


// Print the contents of the list
//
// Input: 
//   Node *head     Pointer to the head node in the existing list
//
// Output:
//   Printout of the linked list content.
//
void printList(Node *head);


// Free the memory from the list
//
// Input: 
//   Node *head     Pointer to the head node in the existing list
//
// Output:
//   None.
//
void freeList(Node *head);


#endif

