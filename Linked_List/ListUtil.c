#include "ListUtil.h"
int moveNodeBetweenLists(LinkedList *fromLL, LinkedList *toLL, int index)
{
    ListNode *llFindNode = findNode(fromLL, index);
    ListNode *llFindPreNode = findNode(fromLL, index-1);

    if (llFindNode == NULL)
        return -1;

    ListNode *lastToLLNode = findNode(toLL, toLL->size - 1);
    if (llFindPreNode == NULL) {
        if (lastToLLNode == NULL) {
            toLL->head = llFindNode;
            fromLL->head = llFindNode->next;
            fromLL->size--;
            llFindNode->next = NULL;
            toLL->size++;
        }
        else {
            lastToLLNode->next = llFindNode;
            fromLL->head = llFindNode->next;
            fromLL->size--;
            lastToLLNode->next->next = NULL;
            toLL->size++;
        }
        return 0;
    }


    if (llFindPreNode->next->next == NULL) {
        llFindPreNode->next = NULL;
        fromLL->size--;
    }	else {
        ListNode *tempNode = llFindPreNode->next->next;
        llFindPreNode->next = tempNode;
        fromLL->size--;
    }

    if (lastToLLNode == NULL) {
        llFindNode->next = NULL;
        toLL->head = llFindNode;
        toLL->size++;
    }
    else {
        llFindNode->next = NULL;
        lastToLLNode->next = llFindNode;
        toLL->size++;
    }

    return index;
}


LinkedList* appendList(LinkedList *ll1, LinkedList* ll2) {
    ListNode * ll1Node = ll1->head;
    while (ll1Node->next != NULL) {
        ll1Node = ll1Node->next;
    }

    ll1Node->next = ll2->head;

    return ll1;
}

int findIndex(LinkedList *ll, ListNode *node) {
    ListNode *llNode = ll->head;
    int index = 0;
    while (llNode->next != NULL) {
        if (llNode == node) {
            return index;
        }
        llNode = llNode->next;
        index++;
    }

    return -1;
}