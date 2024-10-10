#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* pNext;
};

struct List {
    Node* pHead;
    Node* pTail;
};

void Init(List& list) {
    list.pHead = list.pTail = nullptr;
}

void AppendList(List& list, int arr[], int n) {
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        newNode->data = arr[i];
        newNode->pNext = nullptr;

        if (list.pHead == nullptr) {
            list.pHead = list.pTail = newNode;
        } else {
            list.pTail->pNext = newNode;
            list.pTail = newNode;
        }
    }
}

int RemoveNodesK(List& list, int k) {
    int count = 0;
    Node* prev = nullptr;
    Node* curr = list.pHead;

    while (curr != nullptr) {
        if (curr->data == k) {
            if (prev == nullptr) {
                list.pHead = curr->pNext; 
            } else {
                prev->pNext = curr->pNext;
            }
            Node* toDelete = curr; 
            curr = curr->pNext;
            delete toDelete; 
            count++; 
        } else {
            prev = curr; 
            curr = curr->pNext; 
        }
    }

    return count; 
}


