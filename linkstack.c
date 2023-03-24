#include <stdio.h>
#include <stdlib.h>

#define TURE 1
#define FALSE 0

typedef struct Node{
	int data;
	struct Node* next;
}Node;
// 初始化栈
Node* initStack(){
	Node* S = (Node*)malloc(sizeof(Node));
	S -> data = 0;
	S -> next = NULL;
	return S;
}
// 出栈
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
// 获取栈顶元素 
int getTop(Node* S){
	if(isEmpty(S)){
		return -1;
	}
	else{
		return S->next->data;
	}
}
// 入栈
void Push(Node* S,int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	node -> next = S -> next;
	S -> next = node;
	S -> data++;
}
// 判断栈是否为空
int isEmpty(Node* S){
	if(S->data==0||S->next==NULL){
		return TURE;
	}
	else{
		return FALSE;
	}
}
// 遍历
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
