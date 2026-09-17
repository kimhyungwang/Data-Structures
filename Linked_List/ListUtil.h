//
// Created by jungle on 26. 9. 11..
//

#ifndef DATA_STRUCTURES_DOCKER_LISTUTIL_H
#define DATA_STRUCTURES_DOCKER_LISTUTIL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int item;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist
{
    int size;
    ListNode *head;
} LinkedList;

int moveNodeBetweenLists(LinkedList *fromLL, LinkedList *toLL, int index);
LinkedList *appendList(LinkedList *ll1, LinkedList *ll2);
int findIndex(LinkedList *ll, ListNode *node);

ListNode *findNode(LinkedList *ll, int index);

#endif //DATA_STRUCTURES_DOCKER_LISTUTIL_H
