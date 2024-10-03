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

void ShowList(const List& list) {
    Node* current = list.pHead;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->pNext;           
    }
    std::cout << std::endl;
}
