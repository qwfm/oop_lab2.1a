#include "ListNode.h"

long getAddress(int id, ListNode* head) {
    if (id < 1) {
        return -1;
    }

    ListNode* temp = head;
    while (temp) {
        if (temp->id == id) {
            return temp->address;
        }
        temp = temp->next;
    }
    return -1;
}

bool isIdFree(int id, ListNode* head) {
    if (id < 1) {
        return false;
    }

    if (!head) {
        return false;
    }

    ListNode* temp = head;
    while (temp) {
        if (temp->id == id) {
            return false;
        }
        temp = temp->next;
    }

    return true;
}

void addListNode(int id, long address, ListNode** head) {

    if (!isIdFree(id, *head)) {
        std::cerr << "This ID is already taken.\n";
        return;
    }

    if (address < 0) {
        std::cerr << "Address is out of range\n";
        return;
    }

    if ((*head)->id == -1) {
        (*head)->id = id;
        (*head)->address = address;
        return;
    }

    ListNode* temp = new ListNode;
    temp->id = id;
    temp->address = address;

    temp->next = *head;
    (*head) = temp;
}

void deleteListNode(int id, ListNode** head) {

    if (isIdFree(id, *head)) {
        return;
    }

    if ((*head)->id == id) {
        if ((*head)->next == nullptr) {
            (*head)->id = -1;
            (*head)->address = -1;
            return;
        }
        ListNode* temp = *head;
        *head = (*head)->next;
        delete temp;
        return;
    }

    ListNode* temp = *head;
    while (temp->next) {
        if (temp->next->id == id) {
            ListNode* toRemove = temp->next;
            temp->next = temp->next->next;
            delete toRemove;
            return;
        }
        temp = temp->next;
    }
}

void sortList(ListNode** head) {
    if (!(*head) || !(*head)->next) {
        return;
    }

    bool swapped;
    ListNode* current;
    ListNode* lastSorted = nullptr;

    do {
        swapped = false;
        current = *head;

        while (current->next != lastSorted) {
            if (current->id > current->next->id) {
                int tempId = current->id;
                long tempAddress = current->address;

                current->id = current->next->id;
                current->address = current->next->address;

                current->next->id = tempId;
                current->next->address = tempAddress;

                swapped = true;
            }
            current = current->next;
        }
        lastSorted = current;
    } while (swapped);
}

int getSize(ListNode* head) {
    int size = 0;
    ListNode* temp = head;
    while (temp) {
        if (temp->id != -1) {
            ++size;
        }
        temp = temp->next;
    }
    return size;
}

void printList(ListNode* head) {
    if (!head) {
        std::cerr << "Invalid list head pointer.\n";
        return;
    }

    ListNode* temp = head;
    while (temp) {
        std::cout << temp->id << ' ';
        temp = temp->next;
    }
    std::cout << '\n';
}