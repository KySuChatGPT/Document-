#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Student {
    string ID;
    string Name;
    string Gender;
    double Grade;
};

struct Node {
    Student data;
    Node* link;   
};

struct ListStudent {
    Node* first;
    Node* last;
};

// 1. Hàm khởi tạo danh sách liên kết
void Initial(ListStudent &list) {
    list.first = nullptr;
    list.last = nullptr;
}

// 2. Hàm đọc dữ liệu sinh viên từ tệp
void ReadStudent(ListStudent &list, const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open the file!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student student;
        string gradeStr;

        // Đọc dữ liệu từ dòng
        getline(ss, student.ID, ',');
        getline(ss, student.Name, ',');
        getline(ss, student.Gender, ',');
        getline(ss, gradeStr, ',');
        student.Grade = stod(gradeStr);

        // Tạo nút mới
        Node* newNode = new Node;
        newNode->data = student;
        newNode->link = nullptr;

        // Chèn nút vào cuối danh sách
        if (list.first == nullptr) {
            list.first = newNode;
            list.last = newNode;
        } else {
            list.last->link = newNode;
            list.last = newNode;
        }
    }
}

// 3. Hàm sắp xếp danh sách sinh viên theo điểm số
void SLListSort(ListStudent &list) {
    if (list.first == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = list.first;
        while (current->link != nullptr) {
            if (current->data.Grade > current->link->data.Grade) {
                swap(current->data, current->link->data);
                swapped = true;
            }
            current = current->link;
        }
    } while (swapped);
}

// 4. Hàm hiển thị n sinh viên đầu tiên trong danh sách
void ShowStudentHeads(ListStudent &list, int n) {
    Node* current = list.first;
    int count = 0;
    while (current != nullptr && count < n) {
        cout << current->data.ID << "\t"
             << current->data.Name << "\t"
             << current->data.Gender << "\t"
             << current->data.Grade << endl;
        current = current->link;
        count++;
    }
}
