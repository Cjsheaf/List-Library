/**
 * File: LinkedList.h
 * Author: Christopher Sheaf
 * Modified: 11/29/13
 *
 * Description: A basic linked-list implementation designed for ease-of-use at the cost of some speed.
 *
 * Implementation Notes: Caches the last node operated on, so consecutive operations on the same list shouldn't incur much of a speed penalty.
 *    In the future, a function to append items to the head of the linked list would be useful, but for consistency the other data structures would
 *    need to support it as well.
 */
 
typedef struct Node Node; //Forward declaration of Node so that it may be referenced in the Node struct
struct Node {
	void* item;
	Node* next;
};

typedef struct {
	Node* head;
	Node* tail;
	int size;
} LinkedList;

LinkedList* createLinkedList();
void deleteLinkedList(LinkedList* list); /** Only works if all Nodes were created with functions from this library. Behavior is undefined otherwise (likely a crash). **/

void addToLinkedList(LinkedList* list, void* item); //Adds the item to the END of the LinkedList, for consistency with the other List data structures
void removeFromLinkedList(LinkedList* list, int index);
void* getFromLinkedList(LinkedList* list, int index);