//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Lab Test: Section A - Linked List Questions
Purpose: Implementing the required functions for Question 7 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode
{
	int item;
	struct _listnode *next;
} ListNode; // You should not change the definition of ListNode

typedef struct _linkedlist
{
	int size;
	ListNode *head;
} LinkedList; // You should not change the definition of LinkedList

//////////////////////// function prototypes /////////////////////////////////////

// You should not change the prototype of this function
void RecursiveReverse(ListNode **ptrHead);

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

int moveNodeBetweenLists(LinkedList *fromLL, LinkedList *toLL, int index);
LinkedList *appendList(LinkedList *ll1, LinkedList *ll2);
int findIndex(LinkedList *ll, ListNode *node);

void testF(ListNode **ptrHead);

//////////////////////////// main() //////////////////////////////////////////////

int main()
{
	LinkedList ll;
	int c, i, j;
	c = 1;
	// Initialize the linked list 1 as an empty linked list
	ll.head = NULL;
	ll.size = 0;

	printf("1: Insert an integer to the linked list:\n");
	printf("2: Reversed the linked list:\n");
	printf("0: Quit:\n");

	insertNode(&ll, 0, 1);
	insertNode(&ll, 0, 2);
	insertNode(&ll, 0, 3);
	insertNode(&ll, 0, 4);

	// testF(&(ll.head));
	// RecursiveReverse(&(ll.head)); // You need to code this function

	while (c != 0)
	{
		printf("Please input your choice(1/2/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list: ");
			scanf("%d", &i);
			j = insertNode(&ll, ll.size, i);
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 2:
			RecursiveReverse(&(ll.head)); // You need to code this function
			printf("The resulting linked list after reversed the given linked list is: ");
			printList(&ll);
			removeAllItems(&ll);
			break;
		case 0:
			removeAllItems(&ll);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////

void testF(ListNode **ptrHead)
{
	ListNode *t4 = *ptrHead;

	t4->item = 777;

	return;
}

void RecursiveReverse(ListNode **ptrHead)
{
	/* add your code here */

	printf("item : %d\n", (**ptrHead).item);
	if ((**ptrHead).next == NULL)
	{
		// ListNode **newHead = malloc(sizeof(ListNode));0xffffc99c1be8
		// newHead = ptrHead;0xaaaaf4f65420.  0xaaaaf4f65440. 0xffffd0524c68

		return;
	}

	ListNode **tempHead = ptrHead;
	ListNode *tempNext = (**ptrHead).next;
	ListNode *NextNext = (**ptrHead).next->next;
	// (**tempHead).next = NextNext;
	// tempNext->next = *ptrHead;
	// ptrHead = &tempNext;

	//(**ptrHead).next = NextNext;
	// (**tempHead).next = tempNext;
	// ptrHead = &tempNext;
	// tempNext = *ptrHead;
	// (**ptrHead).next = *tempHead;

	// ptrHead = &(**ptrHead).next;
	// (**ptrHead).next = *tempHead;

	// RecursiveReverse(&(**ptrHead).next);
	// RecursiveReverse(&(**ptrHead).next);
	RecursiveReverse(&tempNext);
	printf("return : %d \n", (**ptrHead).item);
	(*ptrHead)->next->next = *ptrHead;
	(**ptrHead).next = NULL;
	*ptrHead = tempNext;

	// *ptrHead = rest;
	// ListNode *tempHead2 = &(**ptrHead);
	// ListNode **tempHead = ptrHead;
	// ListNode *tempNext = (**ptrHead).next;
	// ListNode *t4 = *ptrHead;
	// (*tempHead)->next = NULL;
	// ptrHead = &tempNext; //
	// (**ptrHead).next = *tempHead;
	// ListNode **tttt = &(*ptrHead);
	// t4 = *ptrHead;

	//&ptrHead =
	//&(ptrHead) = (tempNext);
	// for (ListNode *node = (*ptrHead); node->next != NULL; ptrHead = &(**ptrHead).next)
	// 	RecursiveReverse((&node));
}

int moveNodeBetweenLists(LinkedList *fromLL, LinkedList *toLL, int index)
{
	ListNode *llFindNode = findNode(fromLL, index);
	ListNode *llFindPreNode = findNode(fromLL, index - 1);

	if (llFindNode == NULL)
		return -1;

	ListNode *lastToLLNode = findNode(toLL, toLL->size - 1);
	if (llFindPreNode == NULL)
	{
		if (lastToLLNode == NULL)
		{
			toLL->head = llFindNode;
			fromLL->head = llFindNode->next;
			fromLL->size--;
			llFindNode->next = NULL;
			toLL->size++;
		}
		else
		{
			lastToLLNode->next = llFindNode;
			fromLL->head = llFindNode->next;
			fromLL->size--;
			lastToLLNode->next->next = NULL;
			toLL->size++;
		}
		return 0;
	}

	if (llFindPreNode->next->next == NULL)
	{
		llFindPreNode->next = NULL;
		fromLL->size--;
	}
	else
	{
		ListNode *tempNode = llFindPreNode->next->next;
		llFindPreNode->next = tempNode;
		fromLL->size--;
	}

	if (lastToLLNode == NULL)
	{
		llFindNode->next = NULL;
		toLL->head = llFindNode;
		toLL->size++;
	}
	else
	{
		llFindNode->next = NULL;
		lastToLLNode->next = llFindNode;
		toLL->size++;
	}

	return index;
}

LinkedList *appendList(LinkedList *ll1, LinkedList *ll2)
{
	ListNode *ll1Node = ll1->head;
	while (ll1Node->next != NULL)
	{
		ll1Node = ll1Node->next;
	}

	ll1Node->next = ll2->head;

	return ll1;
}

int findIndex(LinkedList *ll, ListNode *node)
{
	ListNode *llNode = ll->head;
	int index = 0;
	while (llNode->next != NULL)
	{
		if (llNode == node)
		{
			return index;
		}
		llNode = llNode->next;
		index++;
	}

	return -1;
}

//////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll)
{

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}

ListNode *findNode(LinkedList *ll, int index)
{

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0)
	{
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value)
{

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0)
	{
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}

	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL)
	{
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}

int removeNode(LinkedList *ll, int index)
{

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0)
	{
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL)
	{

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}

void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
}
