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

void Initial(ListStudent& list) {
    list.first = nullptr;
    list.last = nullptr;
}

// Insert a student at the beginning of the linked list
void InsertFirst(ListStudent& list, const Student& student) {
    Node* newNode = new Node(); 
    newNode->data = student;
    newNode->link = list.first; 
    list.first = newNode; 

    if (list.last == nullptr) {
        list.last = newNode;
    }
}

// Show all students in the linked list
void ShowListStudent(const ListStudent& list) {
    Node* current = list.first;
    while (current != nullptr) {
        cout << current->data.ID << "\t"
             << current->data.Name << "\t"
             << current->data.Gender << "\t"
             << current->data.Born.month << "/" << current->data.Born.day << "/" << current->data.Born.year << endl;
        current = current->link;
    }
}


