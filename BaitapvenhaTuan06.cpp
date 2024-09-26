#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> // Th�m thu vi?n d? s? d?ng h�m pow

struct Node {
    float data; // C�c to�n h?ng ki?u s? th?c
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

// Th�m m?t ph?n t? v�o stack
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
    return 0; // Tr? v? gi� tr? m?c d?nh khi stack r?ng
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
    tu[i] = '\0'; // K?t th�c chu?i
}

int LaToanTu(char s[]) {
    char c = s[0]; // Ki?m tra k� t? d?u ti�n
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') ? 1 : 0; // Th�m '^' v�o ki?m tra
}

float TinhToan(float toanHang1, float toanHang2, char toanTu) {
    switch (toanTu) {
        case '+': return toanHang2 + toanHang1; // Th?c hi?n ph�p c?ng
        case '-': return toanHang2 - toanHang1; // Th?c hi?n ph�p tr?
        case '*': return toanHang2 * toanHang1; // Th?c hi?n ph�p nh�n
        case '/':
            if (toanHang1 != 0) // Ki?m tra chia cho 0
                return toanHang2 / toanHang1;
            else {
                printf("Error: Division by zero\n");
                return 0;
            }
        case '^': return pow(toanHang2, toanHang1); // Th?c hi?n ph�p luy th?a
    }
    return 0; // Tru?ng h?p m?c d?nh
}

float TinhBieuThuc(Stack& s, char bieuThuc[]) {
    float kq;
    char t[10];
    int i = 0;

    do {
        DocTu(bieuThuc, t, i);
        if (LaToanTu(t)) { // N?u t l� m?t to�n t?
            char toanTu = t[0]; // To�n t? ch? c� m?t k� t?
            float toanHang1 = Pop(s);
            float toanHang2 = Pop(s);
            kq = TinhToan(toanHang2, toanHang1, toanTu); // T�nh to�n
            Push(s, kq); // �ua k?t qu? v�o stack
        } else if (strlen(t) > 0) { // N?u l� to�n h?ng
            float toanHang = atof(t); // Chuy?n th�nh s? th?c
            Push(s, toanHang); // �ua to�n h?ng v�o stack
        }
        i++;
    } while (bieuThuc[i] != '#' && bieuThuc[i] != '\0'); // D?ng t?i '#' ho?c k?t th�c chu?i

    return Pop(s); // K?t qu? cu?i c�ng
}

int main() {
    Stack s;
    Init(s);
    char bieuThuc[100] = "";

    printf("Nhap bieu thuc dang hau to (ket thuc bang '#'):\n");
    fgets(bieuThuc, sizeof(bieuThuc), stdin); // �?c d?u v�o an to�n
    float kq = TinhBieuThuc(s, bieuThuc);
    printf("\nGia tri cua bieu thuc la: %.2f\n", kq); // In k?t qu?

    return 0;
}

