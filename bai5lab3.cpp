#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* pNext;
};

struct List {
    Node* pHead;
    Node* pTail;
    
    List() : pHead(nullptr), pTail(nullptr) {}  
};

void insertAtHead(List& list, int value) {
    Node* newNode = new Node{value, nullptr};
    if (list.pHead == nullptr) {
        list.pHead = list.pTail = newNode;
    } else {
        newNode->pNext = list.pHead;
        list.pHead = newNode;
    }
}

void insertAtTail(List& list, int value) {
    Node* newNode = new Node{value, nullptr};
    if (list.pHead == nullptr) {
        list.pHead = list.pTail = newNode;
    } else {
        list.pTail->pNext = newNode;
        list.pTail = newNode;
    }
}

List CreateLinkedListFromFile(const string& filename) {
    List list;
    ifstream file(filename);
    string line;
    
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            int value, option;
            char comma;

            ss >> value >> comma >> option;
            
            if (option == 0) {
                insertAtHead(list, value);  
            } else if (option == -1) {
                insertAtTail(list, value);  
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
    }
    
    return list;
}

void ShowHead(const List& list, int k) {
    Node* current = list.pHead;
    int count = 0;
    
    while (current != nullptr && count < k) {
        cout << current->data << " ";
        current = current->pNext;
        count++;
    }
    cout << endl;
}
