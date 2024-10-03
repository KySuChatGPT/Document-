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

void InsertLast(List& list, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->pNext = nullptr; 

    if (list.pTail != nullptr) {
        list.pTail->pNext = newNode; 
    } else {
        list.pHead = newNode; 
    }
    list.pTail = newNode; 
}

void FindAndInsert(List& list, int x, int y) {
    Node* current = list.pHead;

    while (current != nullptr) {
        if (current->data == x) {
            Node* newNode = new Node;
            newNode->data = y;
            newNode->pNext = current->pNext; 
            current->pNext = newNode; 
            if (newNode->pNext == nullptr) {
                list.pTail = newNode; 
            }
            return;
        }
        current = current->pNext;
    }

    InsertFirst(list, y);
}

void ShowList(const List& list) {
    Node* current = list.pHead;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->pNext;
    }
    std::cout << std::endl;
}
