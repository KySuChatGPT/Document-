#include <iostream>
#include <string>

using namespace std;

struct BirthDay {
    int day;
    int month;
    int year;
};

struct Student {
    string ID;
    string Name;
    string Gender;
    BirthDay Born;
};

struct Node {
    Student data;
    Node* link;
};

struct ListStudent {
    Node* first;
    Node* last;
};

void Initial(ListStudent& L) {
    L.first = L.last = nullptr;
}

void InsertNode(ListStudent& L, Node* p) {
    if (L.first == nullptr) {
        L.first = L.last = p;
    } else if (p->data.ID < L.first->data.ID) {
        p->link = L.first;
        L.first = p;
    } else {
        Node* q = L.first;
        while (q->link != nullptr && p->data.ID > q->link->data.ID) {
            q = q->link;
        }
        p->link = q->link;
        q->link = p;
        if (p->link == nullptr) {
            L.last = p;
        }
    }
}

void InsertOrderStudents(ListStudent& L, Student st[], int n) {
    for (int i = 0; i < n; i++) {
        Node* p = new Node;
        p->data = st[i];
        p->link = nullptr;
        InsertNode(L, p);
    }
}

void ShowListStudent(ListStudent L) {
    Node* p = L.first;
    while (p != nullptr) {
        cout << p->data.ID << "\t" << p->data.Name << "\t"
             << p->data.Gender << "\t" << p->data.Born.month << "/"
             << p->data.Born.day << "/" << p->data.Born.year << endl;
        p = p->link;
    }
}
