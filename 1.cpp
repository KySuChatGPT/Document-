#include <iostream>
#include <string>

using namespace std;

struct BirthDay {
    int day;
    int month;
    double year;
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

// 1. Initialize an empty linked list
void Initial(ListStudent& list) {
    list.first = nullptr;
    list.last = nullptr;
}

// 2. Insert a student at the end of the linked list
void InsertLast(ListStudent& list, const Student& student) {
    Node* newNode = new Node();
    newNode->data = student;
    newNode->link = nullptr;

    if (list.first == nullptr) { // If the list is empty
        list.first = newNode;
        list.last = newNode;
    } else { // If the list is not empty
        list.last->link = newNode;
        list.last = newNode;
    }
}

// 3. Show all students in the linked list
void ShowListStudent(const ListStudent& list) {
    Node* current = list.first;
    while (current != nullptr) {
        cout << current->data.ID << "\t"
             << current->data.Name << "\t"
             << current->data.Gender << "\t"
              << current->data.Born.month << "/"<< current->data.Born.day << "/" << current->data.Born.year << endl;
        current = current->link;
    }
}
