/**
 * File: ArrayList.c
 * Author: Christopher Sheaf
 * Modified: 11/29/13
 *
 * Description: A basic array-list implementation designed for ease-of-use at the cost of some speed.
 */

#include <stdlib.h>
#include <stdio.h>

#include "..\Header Files\ArrayList.h"

ArrayList* createArrayList() {
	ArrayList* newList = malloc(sizeof(ArrayList));
	newList->arrayLength = 0;
	newList->size = 0;
	
	return newList;
}
void deleteArrayList(ArrayList* list) { //NOTE: does not make the original pointer to the list NULL
	int i;
	if(list != NULL) {
		for(i = 0; i < list->size; i++) {
			free((list->items)[i]);
		}
		free(list->items);
		free(list);
	}
}

void addToArrayList(ArrayList* list, void* newItem) {
	if(list->arrayLength == 0) {
		list->arrayLength = 5;
		list->items = malloc(sizeof(void*) * list->arrayLength);
		if(list->items == NULL) {
			printf("\nERROR: Unable to allocate memory for the ArrayList!");
			exit(1);
		}
	} else if(list->size >= list->arrayLength) {
		list->arrayLength = list->arrayLength * 2;
		list->items = realloc(list->items, sizeof(void*) * list->arrayLength);
		if(list->items == NULL) {
			printf("\nERROR: Unable to re-allocate memory for the ArrayList!");
			exit(1);
		}
	}
	list->items[list->size] = newItem;
	list->size++;
}
void removeFromArrayList(ArrayList* list, int index) {
	int i;
	
	free(list->items[index]);
	for(i = index + 1; i < list->size; i++) { //Shift every element past index to the left by one
		list->items[i - 1] = list->items[i];
	}
	list->size--;
}
void* getFromArrayList(ArrayList* list, int index) {
	if(index >= list->size) {
		return NULL;
	} else {
		return list->items[index];
	}
}