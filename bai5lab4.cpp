#include <iostream>

struct Node {
    int data;
    Node* pNext;
};

struct List {
    Node* pHead;
    Node* pTail;
};

void Init(List& list) {
    list.pHead = nullptr;
    list.pTail = nullptr;
}

void AppendList(List& list, int* arr, int size) {
    for (int i = 0; i < size; i++) {
        Node* newNode = new Node;
        newNode->data = arr[i];
        newNode->pNext = nullptr;

        if (list.pHead == nullptr) {
            list.pHead = newNode;
            list.pTail = newNode;
        } else {
            list.pTail->pNext = newNode;
            list.pTail = newNode;
        }
    }
}

int CountKLinkedList(List& list, int k) {
    int count = 0;
    Node* current = list.pHead;
    while (current != nullptr) {
        if (current->data == k) {
            count++;
        }
        current = current->pNext;
    }
    return count;
}
