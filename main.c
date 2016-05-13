/////////////////////////////////////////////////////////////////
//
// Demo of linked list functions. Input file must contain lines
// with the following data, separated by spaces.
//
//   int name (integer "name" of a city)
//   int x    (X coordinate)
//   int y    (Y coordinate)
//
// Adjust the code accordingly if your list nodes are different.
//
// File:    main.c
// Author:  Erik Ratcliffe (erat@modal.us)
// Version: 0.1 
// Date:    May, 2016
//
//
// TO BUILD:
// =============================================================
//
// With all source files (llist.h, llist.c, main.c) in the same
// directory, run the following command:
//
//    gcc -o llist llist.c main.c
//
//
// TO RUN:
// =============================================================
//
// Running the llist program without passing an input file will
// give you usage instructions. Pass an input file and everything
// should run correctly.
//
// 1. The input file content is read into a linked list.
//
// 2. A new node is added to the list after node "5".
//
// 3. The new node is deleted.
//
// 4. A new linked list is created that has the content from the
//    original list but in reverse order.
//
// 5. A new linked list is created that is a copy of the reversed
//    linked list.
//
// 6. All lists are destroyed.
//
// Phases 2-5 print the results to the console.
//
/////////////////////////////////////////////////////////////////


#include "llist.h"


int main(int argc, char **argv)
{
    Node *head;      // head node
    Node *prev_node; // "previous" to inserted node
    Node *new_node;  // new node to insert
    Node *current;   // points to the current node
    FILE *fp;        // input file pointer


    // Check for sufficient command line arguments. If not found,
    // exit with a usage message and error code.
    //
    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s [input file]\n", argv[0]);
        exit(1);
    }


    // Open the input file.
    //
    fp = fopen(argv[1], "r");
    if(!fp)
    {
        fprintf(stderr, "Error opening input file\n");
        exit(1);
    }


    // Build a linked list from the input file.
    //
    head = fileToList(fp);


    // Close the input file.
    //
    fclose(fp);


    //////////////////////////////////////////////////////////////
    //
    // For giggles, create a node and insert it in the list before
    // the "5" node.
    //
    //////////////////////////////////////////////////////////////
    

    new_node       = malloc(sizeof(Node));
    new_node->name = 21;
    new_node->x    = 100;
    new_node->y    = 200;
    new_node->next = NULL; // This will need to be set later


    // Search the linked list for node 5.
    //
    current = head;
    while(current->name != 5)
    {
        prev_node = current;
        current = current->next;
    }


    // Did the loop above get nowhere? Insert the new
    // node to the beginning of the list. Otherwise, insert 
    // the new node before the found node.
    //
    if(current == head)
    {
        current->next = head;
        head = current;
    }
    else
    {
        insertNode(prev_node, new_node);
    }


    // Print the contents of the list
    //
    printf("Printout of the linked list with the added node...\n");
    printList(head);


    // Delete the node you just added.
    //
    // First, locate the node you just added, then completely
    // delete/free it.
    //
    current = head;
    while(current->name != 21)
    {
        prev_node = current;
        current = current->next;
    }
    deleteNode(prev_node, current);


    // Print the contents of the list
    //
    printf("\n");
    printf("Printout of the linked list after deleting added node...\n");
    printList(head);


    //////////////////////////////////////////////////////////////
    //
    // Also for giggles, reverse the linked list.
    //
    //////////////////////////////////////////////////////////////
    
    
    Node *newHead;
    newHead = revList(head);


    // Print the contents of the reversed list
    //
    printf("\n");
    printf("Printout of the reversed linked list...\n");
    printList(newHead);


    //////////////////////////////////////////////////////////////
    //
    // No more giggles. Just copy the linked list.
    //
    //////////////////////////////////////////////////////////////


    Node *newCopy;
    newCopy = copyList(newHead);


    // Print the contents of the reversed list
    //
    printf("\n");
    printf("Printout of the COPY OF the reversed linked list...\n");
    printList(newCopy);


    //////////////////////////////////////////////////////////////
    //
    // Free the memory from the lists and exit.
    //
    //////////////////////////////////////////////////////////////


    freeList(head);
    freeList(newHead);
    freeList(newCopy);

    return 0;
}

