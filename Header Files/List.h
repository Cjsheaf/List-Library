/**
 * File: List.h
 * Author: Christopher Sheaf
 * Modified: 11/29/13
 *
 * Description: A wrapper for the (currently 2) other list data structures in the list library.
 *     Provides a pseudo-polymorphic way to create and manipulate any of the data structures,
 *     and makes it easy to change the data structure being used, at a later date.
 */

//List type constants to be used with the createList() function:
static const int ARRAY_LIST = 1;
static const int LINKED_LIST = 2;

typedef struct {
	int listType;
	void* listInstance;
} List;

List* createList(int listType);
void deleteList(List* list);

void addToList(List* list, void* item);
void removeFromList(List* list, int index);
void* getFromList(List* list, int index);

int listSize(List* list);