#include<stdio.h>

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

int main(){
	stack s;
	Init(s);
	Push(s,10);
	Push(s,20);
	Push(s,30);
	while(!Empty(s)){
		printf("%.0f ",Pop(s));
	}	
}
































