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

int RemoveHead(List& list) {
    if (list.pHead == nullptr) return 0;

    Node* temp = list.pHead;
    int value = temp->data;
    list.pHead = list.pHead->pNext;

    delete temp;
    if (list.pHead == nullptr) {
        list.pTail = nullptr;
    }
    return value;
}

