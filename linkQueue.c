#include <stdio.h> 
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;
Node* initQueue(){
	Node* Q = (Node*)malloc(sizeof(Node));
	Q -> data = 0;
	Q -> next = NULL;
	return Q;
}
int isEmpty(Node* Q){
	if(Q->data==0||Q->next==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
void inQueue(Node* Q,int data){
	Node* q = Q;
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	int i = 0;
	for(i=0;i<Q->data;i++){
		q = q -> next;
	}
	node -> next = q -> next;
	q -> next = node;
	Q -> data++;
}
int deQueue(Node* Q){
	if(isEmpty(Q)){
		return -1;
	}
	else{
		Node* node = Q -> next;
		int data = node -> data;
		Q -> next = node -> next;
		free(node);
		return data;
	}
}
void Print(Node* Q){
	Node* node = Q -> next;
	while(node){
		printf("%d -> ",node -> data);
		node = node -> next;
	}
	printf("NULL\n");
}
int main(){
	Node* t = initQueue();
	inQueue(t,5);
	inQueue(t,4);
	inQueue(t,3);
	inQueue(t,2);
	Print(t);
	int data = deQueue(t);
	data = deQueue(t);
	data = deQueue(t);
	data = deQueue(t);
	Print(t);
	return 0;
} 
