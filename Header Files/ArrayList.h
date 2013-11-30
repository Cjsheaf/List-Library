/**
 * File: ArrayList.h
 * Author: Christopher Sheaf
 * Modified: 11/29/13
 *
 * Description: A basic array-list implementation designed for ease-of-use at the cost of some speed.
 */

typedef struct {
	void** items;
	int size;
	int arrayLength;
} ArrayList;

ArrayList* createArrayList();
void deleteArrayList(ArrayList* list);

void addToArrayList(ArrayList* list, void* item);
void removeFromArrayList(ArrayList* list, int index);
void* getFromArrayList(ArrayList* list, int index);