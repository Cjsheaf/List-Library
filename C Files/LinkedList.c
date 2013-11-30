/**
 * File: LinkedList.c
 * Author: Christopher Sheaf
 * Modified: 11/29/13
 *
 * Description: A basic linked-list implementation designed for ease-of-use at the cost of some speed.
 *
 * Implementation Notes: Caches the last node operated on, so consecutive operations on the same list shouldn't incur much of a speed penalty.
 *    In the future, a function to append items to the head of the linked list would be useful, but for consistency the other data structures would
 *    need to support it as well.
 */

#include <stdlib.h>
#include <stdio.h>

#include "..\Header Files\LinkedList.h"

/**
 * Declare "private" functions and global variables used only by other functions in this file
 */
Node* createNode();
void deleteNode(Node* node);
Node* traverseLinkedList(LinkedList* list, int index); /** Utility Method for traversing the list to a specific node's index **/

//Global variables for caching the last node accessed. Used to speed up consecutive operations.
LinkedList* cachedList = NULL;
int cachedPosition = 0;
Node* cachedNode;

LinkedList* createLinkedList() {
	LinkedList* newList = malloc(sizeof(LinkedList));
	newList->head = NULL;
	newList->tail = NULL;
	newList->size = 0;
	
	return newList;
}
void deleteLinkedList(LinkedList* list) { /** Only works if all Nodes were created with functions from this library. Behavior is undefined otherwise (likely a crash). **/
	Node* previousNode;
	Node* currentNode = NULL;
	
	if(list != NULL) {
		currentNode = list->head;
	}
	
	while(currentNode != NULL) {
		previousNode = currentNode;
		currentNode = currentNode->next;
		deleteNode(previousNode);
	}
}

void addToLinkedList(LinkedList* list, void* item) { //Adds the item to the END of the LinkedList, for consistency with the other List data structures
	Node* newNode = createNode();
	newNode->item = item;
	
	if(list->size == 0) { //If there are no nodes in the list yet
		list->head = newNode;
		list->tail = newNode;
	} else if(list->size == 1) { //If the head and tail both point to a single node
		list->head->next = newNode;
		list->tail = newNode;
	} else { //If head and tail point to different nodes
		list->tail->next = newNode;
		list->tail = newNode;
	}
	list->size++;
}
void removeFromLinkedList(LinkedList* list, int index) {
	if(index >= list->size) {
		printf("\nERROR: Requested out-of-bounds index, %d, in the Linked List!\n", index);
		return;
	}
	
	if (list->size == 1) {
		deleteNode(list->head);
		list->head = NULL;
	} else {
		if(index == 0) { //If the requested index is the head
			Node* temp = list->head; //Hold a temporary reference to the node so we can delete it after unlinking it
			list->head = list->head->next;
			deleteNode(temp);
		} else if(index == list->size - 1) { //If the requested index is the tail
			Node* previousNode = traverseLinkedList(list, index - 1);
			deleteNode(previousNode->next);
			previousNode->next = NULL;
			list->tail = previousNode;
		} else { //If the requested index is somewhere in the middle of the list
			Node* previousNode = traverseLinkedList(list, index - 1);
			Node* temp = previousNode->next; //Hold a temporary reference to the node so we can delete it after unlinking it
			previousNode->next = previousNode->next->next;
			deleteNode(temp);
		}
	}
	list->size--;
}
void* getFromLinkedList(LinkedList* list, int index) {
	if(index >= list->size) {
		printf("\nERROR: Requested out-of-bounds index, %d, in the Linked List!\n", index);
		return NULL;
	}
	
	return traverseLinkedList(list, index)->item;
}

/** Private utility functions used only by the library **/
Node* createNode() { 
	Node* newNode = malloc(sizeof(Node));
	newNode->item = NULL;
	newNode->next = NULL;
}
void deleteNode(Node* node) {
	free(node->item);
	free(node);
}
Node* traverseLinkedList(LinkedList* list, int index) { /** Utility Function for traversing the list to a specific node's index **/
	Node* currentNode = list->head;
	int i = 0;
	
	if(index >= list->size) {
		printf("\nERROR: Requested out-of-bounds index, %d, in the Linked List!\n", index);
		return NULL;
	}
	
	if(list == cachedList) {
		if(index >= cachedPosition) { //We can start partway through the list if the requested node is farther down
			i = cachedPosition;
			currentNode = cachedNode;
		}
	}
	
	while(i < index) {
		currentNode = currentNode->next;
		i++;
	}
	
	cachedList = list;
	cachedPosition = i;
	cachedNode = currentNode;
	return currentNode;
}