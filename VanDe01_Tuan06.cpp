#include <stdio.h>


struct Node
{
	int data;
	Node *link;
};

struct stack{
	Node* top;
};

// Khoi tao stack

void Init(stack &s){
	s.top = NULL; 
}

// Kiem tra stack rong

int Empty(stack s){
	return s.top == NULL ? 1 : 0;
}

// them xoa 1 phan tu trong stack

void Push(stack &s, float x){
	Node *p;
	p =new Node;
	if(p!=NULL){
		p->data = x;
		p->link = s.top;
		s.top = p;
	}
}

// Trich thong tinh va huy phan tu o dinh stack S

float Pop(stack &s){
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



int main(){
	stack s;
    Init(s);

    Push(s, 10.0);
    Push(s, 20.0);
    Push(s, 30.0);

    while (!Empty(s)) {
        printf("Popped: %.1f\n", Pop(s)); 
    }

    return 0;
}


