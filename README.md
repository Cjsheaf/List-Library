List-Library
============

This is a simple hand-rolled library for storing lists of variables or pointers, created primarily for the experience.
Currently contains two data structure implementations, a Linked List and an Array List.

These data structures can be used individually by importing "ArrayList.h" or "LinkedList.h".
Alternatively, they may be used through the crudely pseudo-polymorphic wrapper, "List.h" which handles keeping track of which data structure was created and calling the appropriate functions on it.

Notes on implementation and use:
 - Uses void pointers internally, so stored data must be cast back to its original type upon retrieval.
 - The Linked List caches the last accessed node, so consecutive accesses aren't slowed down.
 - Included is a windows batch file named "CompileListLibrary.bat" that demonstrates the necessary commands to compile and link the library.
