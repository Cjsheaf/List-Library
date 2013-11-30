/**
 * File: List.c
 * Author: Christopher Sheaf
 * Modified: 11/29/13
 *
 * Description: A wrapper for the (currently 2) other list data structures in the list library.
 *     Provides a pseudo-polymorphic way to create and manipulate any of the data structures,
 *     and makes it easy to change the data structure being used, at a later date.
 */

#include <stdlib.h>
#include <stdio.h>

#include "..\Header Files\List.h"
#include "..\Header Files\LinkedList.h"
#include "..\Header Files\ArrayList.h"

//List type constants to be used with the createList() function:
#define ARRAY_LIST 1
#define LINKED_LIST 2

List* createList(int listType) {
	List* newList = malloc(sizeof(List));
	
	switch(listType) {
		case ARRAY_LIST:
			newList->listType = ARRAY_LIST;
			newList->listInstance = createArrayList();
			break;
		case LINKED_LIST:
			newList->listType = LINKED_LIST;
			newList->listInstance = createLinkedList();
			break;
		default:
			printf("ERROR: Tried to create an undefined type of list!");
			exit(1);
	}
	
	return newList;
}
void deleteList(List* list) {
	switch(list->listType) {
		case ARRAY_LIST:
			deleteArrayList((ArrayList*)list->listInstance);
			free(list);
			break;
		case LINKED_LIST:
			deleteLinkedList((LinkedList*)list->listInstance);
			free(list);
			break;
	}
}

void addToList(List* list, void* item) {
	switch(list->listType) {
		case ARRAY_LIST:
			addToArrayList((ArrayList*)list->listInstance, item);
			break;
		case LINKED_LIST:
			addToLinkedList((LinkedList*)list->listInstance, item);
			break;
	}
}
void removeFromList(List* list, int index) {
	switch(list->listType) {
		case ARRAY_LIST:
			removeFromArrayList((ArrayList*)list->listInstance, index);
			break;
		case LINKED_LIST:
			removeFromLinkedList((LinkedList*)list->listInstance, index);
			break;
	}
}
void* getFromList(List* list, int index) {
	switch(list->listType) {
		case ARRAY_LIST:
			getFromArrayList((ArrayList*)list->listInstance, index);
			break;
		case LINKED_LIST:
			getFromLinkedList((LinkedList*)list->listInstance, index);
			break;
	}
}

int listSize(List* list) {
	switch(list->listType) {
		case ARRAY_LIST:
			return ((ArrayList*)list->listInstance)->size;
			break;
		case LINKED_LIST:
			return ((LinkedList*)list->listInstance)->size;
			break;
	}
}