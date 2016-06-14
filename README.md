# c_linked_list
A set of C functions to help set up and manipulate simple linked lists.

##Some structural details:

My original intent was to port a "traveling salesman problem" (TSP) school
project from Python to C. This effort is still under way, but I figured
the linked list functions would be generally useful without burying them
in a larger source tree so they're offered here as a standalone set.

The input that is expected for these functions follows the TSP input for
the Python project, each line describing a "city" that the salesman needs
to visit:

- int name (integer "name" of a city)
- int x    (X coordinate)
- int y    (Y coordinate)

The records in the input are read into the demo from an input file that is
passed on the demo command line. Each line in the file contains the three
items above, separated by a space. For simplicity, this repo includes a
small input.txt file with a sorted "city" list that can be used in the
demo.

Of course, if you are using a different format for your linked list input,
you will need to adjust the linked list functions to match your input.
This should be fairly self-explanatory if you understand basic C, structs,
and pointers.

##To build the demo (gcc):

This repository includes a simple demonstration of the linked list
functions: main.c. 

There is currently no Makefile, but it's simple enough to build the demo
so Makefiles are not necessary. With all source files (llist.h, llist.c,
main.c) in the same directory, run the following command:

``` gcc -o llist llist.c main.c ```

This will produce an llist binary in the current directory. Add a "-g"
after gcc if you want to compile with debug information, which is required
if you plan to use Valgrind for testing:

``` gcc -g -o llist llist.c main.c ```

##To run:

Running the llist program without passing an input file will give you
usage instructions. Pass an input file as the first argument on the
command line and everything should run correctly.

##What does the demo...demo?

1. The content of the input file is read into a linked list.  2. A new
node is added to the list after node "5," or at the beginning of the
linked list if there is no node "5".  3. The new node is deleted.  4. A
new linked list is created that has the content from the original list but
in reverse order.  5. A new linked list is created that is a copy of the
reversed linked list.  6. All lists are destroyed.

Phases 2-5 print the results to the console.

##Caveats:

I have tested this on Linux (Ubuntu Gnome) using many different size input
sets and no issues were encountered. Yes, Valgrind was used to detect
memory leaks. There weren't any. Fundamentally, linked lists are basic
data structures so there isn't a lot that can go wrong if you understand
how they work. That said, I have not spent days testing this code. If
there are bugs, I'd love to hear about them.

Also, students, don't cheat by using my code and taking credit for it.
Most professors are more concerned about you using code without
attribution than they are about using other peoples' code period, but it's
worth checking. If you use my code for any reason, that's cool, but say
you borrowed my code and point back here. It's the right thing to do.
