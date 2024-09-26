#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	int data;
	Node *link;
	
};

struct stack{
	Node *top;
};
//
void Init(stack &s){
	s.top=NULL;
}
int Empty(stack s){
	return s.top==NULL ? 1:0;
}
//them phan tu
void Push(stack &s, float x){
	Node *p=new Node;
	if(p!=NULL){
		p->data=x;
		p->link=s.top;
		s.top=p;
	}
	
}
//lay phan tu
float Pop(stack &s){
	float x;
	if(!Empty(s)){
		Node *p=s.top;
		s.top=p->link;
		x=p->data;
		delete(p);
		return x;
	}
}
void DocTu(char s[], char tu[], int&vt){
	for(int i=0;i<strlen(tu);i++){
		tu[i]=' ';
	}
	int i=0;
	while(s[vt]!=' '){
		tu[i]=s[vt];
		vt++;
		i++;
	}
}
int LaToantu(char s[]){
	char c=s[0];
	if((c=='+') || (c=='-') || (c=='*') || (c=='/'))
		return 1;
	return 0;
}
float TinhToan(float hangso1, float hangso2, char toantu){
	float kq;
	switch(toantu){
		case '+': kq=hangso1+hangso2; break;
		case '-': kq=hangso1-hangso2; break;
		case '*': kq=hangso1*hangso2; break;
		case '/': kq=hangso1/hangso2; 
	}
	return kq;
}
float TinhBieuThuc(stack &s, char bieuthuc[]){
	float kq;
	char t[10];
	int i=0;
	do{
		DocTu(bieuthuc,t,i);
		if(LaToantu(t)){
			char toanTu=t[0];
			float hangso1=Pop(s);
			float hangso2=Pop(s);
			kq=TinhToan(hangso2,hangso1,toanTu);
			Push(s,kq);
		}else{
			float toanHang=atof(t);
			Push(s,toanHang);
		}
		i++;
	}while(bieuthuc[i]!='#');
	return Pop(s);
}
int main(){
	stack s;
	Init(s);
	char bieuThuc[100]="";
	printf("Nhap bieu thuc dang hau to:\n");
	fflush(stdin);
	gets(bieuThuc);
	float kq;
	kq=TinhBieuThuc(s,bieuThuc);
	printf("Ket qua bieu thuc la:%0.f",kq);
}




















