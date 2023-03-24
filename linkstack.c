#include <stdio.h>
#include <stdlib.h>

#define TURE 1
#define FALSE 0

typedef struct Node{
	int data;
	struct Node* next;
}Node;
// ��ʼ��ջ
Node* initStack(){
	Node* S = (Node*)malloc(sizeof(Node));
	S -> data = 0;
	S -> next = NULL;
	return S;
}
// ��ջ
int Pop(Node* S){
	if(isEmpty(S)){
		return -1;
	}
	else{
		Node* node = S -> next;
		int data = node -> data;
		S -> next = node -> next;
		free(node);
		return data;
	}
} 
// ��ȡջ��Ԫ�� 
int getTop(Node* S){
	if(isEmpty(S)){
		return -1;
	}
	else{
		return S->next->data;
	}
}
// ��ջ
void Push(Node* S,int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	node -> next = S -> next;
	S -> next = node;
	S -> data++;
}
// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Node* S){
	if(S->data==0||S->next==NULL){
		return TURE;
	}
	else{
		return FALSE;
	}
}
// ����
void Print(Node* S){
	Node* node = S -> next;
	while(node){
		printf("%d -> ",node->data);
		node = node -> next;
	}
	printf("NULL\n");
}
int main(){
	Node* S = initStack();
	Push(S,1);
	Push(S,2);
	Push(S,3);
	Push(S,4);
	Print(S);
	int i = Pop(S);
	printf("current elem = %d\n",i);
	Print(S);
	return 0;
}
