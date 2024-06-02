#ifndef DBO_LAB1_LISTNODE_H
#define DBO_LAB1_LISTNODE_H

#include <iostream>
/*!
    \brief Structure of a ListNode
*/
struct ListNode {
    /*! \brief id of a listNode  */ int id = -1;
    /*! \brief adress of a listNode in memory  */ long address = -1;
    /*! \brief pointer to the next listNode  */ ListNode* next = nullptr;
};

long getAddress(int id, ListNode* head);

bool isIdFree(int id, ListNode* head);

void addListNode(int id, long address, ListNode** head);

void deleteListNode(int id, ListNode** head);

void sortList(ListNode** head);

int getSize(ListNode* head);

void printList(ListNode* head);

#endif