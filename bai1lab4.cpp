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

void InsertFirst(List& list, int x) {
    Node* newNode = new Node; 
    newNode->data = x;       
    newNode->pNext = list.pHead; 
    list.pHead = newNode;     

    if (list.pTail == nullptr) {
        list.pTail = newNode;
    }
}

int SearchKey(List& list, int x) {
    Node* current = list.pHead;
    while (current != nullptr) {
        if (current->data == x) {
            return 1; 
        }
        current = current->pNext; 
    }
    return -1;
}
