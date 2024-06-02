#ifndef DBO_LAB1_QUEUE_H
#define DBO_LAB1_QUEUE_H

#include <iostream>

/*!
    \brief Structure of a queue node
*/
struct QueueNode {
    /*! \brief queueNode's address in memory  */ long address = -1;
    /*!  \brief pointer to next node in queue  */ QueueNode* next = nullptr;
};

/*!
    \brief Structure of a queue
*/
struct Queue {
    /*!  \brief queue's last added element  */  QueueNode* head = nullptr;
    /*!  \brief queue's first added element  */ QueueNode* tail = nullptr;
    /*!
    \brief Method returns 0 when queue is empty
    */
    bool isEmpty() const;
    /*!
    \brief Method to push queueNode with a specific address from a queue
    */
    void push(long address);
    /*!
    \brief Method to remove queueNode with a specific address from a queue
    */
    long removeAddress(long address);
    /*!
    \brief Method to pop queueNode's head
    */
    long pop();
};

#endif