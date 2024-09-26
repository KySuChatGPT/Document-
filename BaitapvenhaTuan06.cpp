#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> // Thêm thu vi?n d? s? d?ng hàm pow

struct Node {
    float data; // Các toán h?ng ki?u s? th?c
    Node* link;
};

struct Stack {
    Node* top;
};

// Kh?i t?o stack
void Init(Stack& s) {
    s.top = NULL;
}

// Ki?m tra stack r?ng
int Empty(Stack s) {
    return s.top == NULL ? 1 : 0;
}

// Thêm m?t ph?n t? vào stack
void Push(Stack& s, float x) {
    Node* p = new Node;
    if (p != NULL) {
        p->data = x;
        p->link = s.top;
        s.top = p;
    }
}

// L?y m?t ph?n t? ra kh?i stack
float Pop(Stack& s) {
    if (!Empty(s)) {
        Node* p = s.top;
        s.top = p->link;
        float x = p->data;
        delete p;
        return x;
    }
    return 0; // Tr? v? giá tr? m?c d?nh khi stack r?ng
}

void DocTu(char s[], char tu[], int& vt) {
    for (int i = 0; i < strlen(tu); i++)
        tu[i] = ' ';
    
    int i = 0;
    while (s[vt] != ' ' && s[vt] != '\0') {
        tu[i] = s[vt];
        vt++;
        i++;
    }
    tu[i] = '\0'; // K?t thúc chu?i
}

int LaToanTu(char s[]) {
    char c = s[0]; // Ki?m tra ký t? d?u tiên
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') ? 1 : 0; // Thêm '^' vào ki?m tra
}

float TinhToan(float toanHang1, float toanHang2, char toanTu) {
    switch (toanTu) {
        case '+': return toanHang2 + toanHang1; // Th?c hi?n phép c?ng
        case '-': return toanHang2 - toanHang1; // Th?c hi?n phép tr?
        case '*': return toanHang2 * toanHang1; // Th?c hi?n phép nhân
        case '/':
            if (toanHang1 != 0) // Ki?m tra chia cho 0
                return toanHang2 / toanHang1;
            else {
                printf("Error: Division by zero\n");
                return 0;
            }
        case '^': return pow(toanHang2, toanHang1); // Th?c hi?n phép luy th?a
    }
    return 0; // Tru?ng h?p m?c d?nh
}

float TinhBieuThuc(Stack& s, char bieuThuc[]) {
    float kq;
    char t[10];
    int i = 0;

    do {
        DocTu(bieuThuc, t, i);
        if (LaToanTu(t)) { // N?u t là m?t toán t?
            char toanTu = t[0]; // Toán t? ch? có m?t ký t?
            float toanHang1 = Pop(s);
            float toanHang2 = Pop(s);
            kq = TinhToan(toanHang2, toanHang1, toanTu); // Tính toán
            Push(s, kq); // Ðua k?t qu? vào stack
        } else if (strlen(t) > 0) { // N?u là toán h?ng
            float toanHang = atof(t); // Chuy?n thành s? th?c
            Push(s, toanHang); // Ðua toán h?ng vào stack
        }
        i++;
    } while (bieuThuc[i] != '#' && bieuThuc[i] != '\0'); // D?ng t?i '#' ho?c k?t thúc chu?i

    return Pop(s); // K?t qu? cu?i cùng
}

int main() {
    Stack s;
    Init(s);
    char bieuThuc[100] = "";

    printf("Nhap bieu thuc dang hau to (ket thuc bang '#'):\n");
    fgets(bieuThuc, sizeof(bieuThuc), stdin); // Ð?c d?u vào an toàn
    float kq = TinhBieuThuc(s, bieuThuc);
    printf("\nGia tri cua bieu thuc la: %.2f\n", kq); // In k?t qu?

    return 0;
}

