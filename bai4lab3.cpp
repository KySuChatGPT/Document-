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

void InsertLast(List& list, int x) {
    Node* p = new Node;
    p->data = x;
    p->pNext = nullptr;

    if (list.pHead == nullptr) {
        list.pHead = p;
        list.pTail = p;
    } else {
        list.pTail->pNext = p;
        list.pTail = p;
    }
}

void ShowLast(List list) {
    if (list.pTail == nullptr) {
        cout << "Danh sach rong" << endl;
    } else {
        cout << list.pTail->data << endl;
    }
}
