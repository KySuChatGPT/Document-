#include<stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
	float data; //c�c to�n h?ng ki?u s? th?c
	Node *link;
};
struct stack {
	Node *top;
};
//Kh?i t?o stack
void Init(stack& s){
	s.top = NULL;
}
// Ki?m tra stack r?ng
int Empty(stack s){
	return s.top == NULL ? 1 : 0;
}
// Th�m m?t ph?n t? v�o stack
void Push(stack& s, float x){
		Node *p;
	p =new Node;
	if(p!=NULL){
		p->data = x;
		p->link = s.top;
		s.top = p;
	}
}
// L?y m?t ph?n t? ra kh?i stack
float Pop(stack& s){
	float x;
	if(!Empty(s))
	{
		Node *p = s.top;
		s.top = p->link;
		x = p->data;
		delete(p);
		return x;
	}
}
void DocTu(char s[], char tu[], int&vt)
{
	//Kh?i t?o t? ban d?u ch? ch?a c�c kho?ng tr?ng
	for(int i = 0; i<strlen(tu); i++)
	tu[i]= ' ';
	int i = 0;
	while(s[vt] != ' ')//Trong khi chua g?p kho?ng tr?ng
	{
	tu[i] = s[vt];
	vt++;
	i++;
	}
}
int	LaToanTu(char s[])
{
	char c = s[0];//Ch? c?n ki?m tra ph?n t? d?u c?a chu?i
	if((c == '+') || (c == '-') || (c == '*') ||
	(c == '/'))
	return 1;
	return 0;
}
float TinhToan(float toanHang1, float toanHang2,
char toanTu)
{
	float kq;
	switch (toanTu)
	{
	case '+': kq = toanHang1 + toanHang2; break;
	case '-': kq = toanHang1 - toanHang2; break;
	case '*': kq = toanHang1 * toanHang2; break;
	case '/': kq = toanHang1 / toanHang2;
	}
	return kq;
}

float TinhBieuThuc(stack&s, char bieuThuc[])
{
	float kq;
	char t[10] ;
	int i=0;
do
{
	DocTu(bieuThuc, t, i);//Trong chu?i bieuThuc, d?c
	if(LaToanTu(t)) //N?u t l� m?t to�n t?
	{
	char toanTu = t[0]; //To�n t? ch? c� 1 k� t?
	float toanHang1 = Pop(s);
	float toanHang2 = Pop(s);
	kq = TinhToan(toanHang2, toanHang1, toanTu);
	//th?c hi?n ph�p t�nh
	Push(s, kq); //t�nh xong dua kq v�o stack
	}
	else//t l� to�n h?ng
	{	
	float toanHang = atof(t); //chuy?n th�nh s? th?c
	Push(s, toanHang); //dua to�n h?ng v�o stack
	}
	i++;
	}while(bieuThuc[i]!='#'); //Gi? s? quy u?c �#� l� k� t?
	return Pop(s);
}


int main()
{
	stack s;
	Init(s);
	char bieuThuc[100] = "";
	printf("Nhap bieu thuc dang hau to\n");
	fflush(stdin);
	gets(bieuThuc);
	float kq;
	kq = TinhBieuThuc(s, bieuThuc);
	printf("\nGia tri cua bieu thuc la: %f \n", kq);
}
