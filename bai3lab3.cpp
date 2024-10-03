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
    list.pHead = nullptr;
    list.pTail = nullptr;
}

void InsertFirst(List& list, int x) {
    Node* p = new Node;
    p->data = x;
    p->pNext = list.pHead;

    list.pHead = p;
    if (list.pTail == nullptr) {
        list.pTail = p;
    }
}

void ShowFirst(List list) {
    if (list.pHead == nullptr) {
        cout << "Danh sach rong" << endl;
    } else {
        cout << list.pHead->data << endl;
    }
}
