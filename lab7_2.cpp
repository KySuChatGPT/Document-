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

// Khởi tạo danh sách rỗng
void Initial(ListStudent& L) {
    L.first = L.last = nullptr;
}

// Thêm một node vào cuối danh sách
void AppendNode(ListStudent& L, Node* p) {
    if (L.first == nullptr) {
        L.first = L.last = p;
    } else {
        L.last->link = p;
        L.last = p;
    }
}

// Thêm các sinh viên vào cuối danh sách
void AppdendStudents(ListStudent& L, Student st[], int n) {
    for (int i = 0; i < n; i++) {
        Node* p = new Node;
        p->data = st[i];
        p->link = nullptr;
        AppendNode(L, p);
    }
}

// Xóa một sinh viên theo ID
int RemoveIDStudent(ListStudent& L, string ID) {
    Node* p = L.first;
    Node* q = nullptr;
    while (p != nullptr && p->data.ID != ID) {
        q = p;
        p = p->link;
    }
    if (p == nullptr) {
        return -1; // Không tìm thấy
    }
    if (q == nullptr) {
        L.first = p->link;
    } else {
        q->link = p->link;
    }
    if (p == L.last) {
        L.last = q;
    }
    delete p;
    return 1;
}

// Hiển thị danh sách sinh viên
void ShowListStudent(ListStudent L) {
    Node* p = L.first;
    while (p != nullptr) {
        cout << p->data.ID << "\t" << p->data.Name << "\t"
             << p->data.Gender << "\t" << p->data.Born.month << "/"
             << p->data.Born.day << "/" << p->data.Born.year << endl;
        p = p->link;
    }
}
