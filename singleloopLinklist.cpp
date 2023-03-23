#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node{
	int data;
	struct Node* next;
}Node;
// 初始化单链表
Node* initList(){
	Node* L = (Node*)malloc(sizeof(Node));
	L -> data = 0;
	L -> next = L;
	return L;
} 
// 头插法
void headInsert(Node* L,int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	node -> next = L -> next;
	L -> next = node;
	L -> data++;
}
//尾插法
void tailInsert(Node* L,int data){
	Node* n = L;
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	while(n->next!=L){
		n = n->next;
	}
	node -> next = L;
	n -> next = node;
} 
//删除操作
int Delete(Node* L,int data){
	Node* preNode = L;
	Node* node = L -> next;
	while(node != L){
		if(node -> data == data){
			//   当前结点的next赋给前一个结点的next 
			preNode -> next = node -> next;
			free(node);
			return TRUE;
		}
		preNode = node;
		node = node -> next;
	}
	return FALSE;
} 
//遍历
void printList(Node* L){
	Node* node = L -> next;
	while(node != L){
		printf("%d->",node->data);
		node = node -> next;
	}
	printf("NULL\n");
} 
int main(){
	Node* test = initList();
	for(int i=1;i<7;i++){
		headInsert(test,i);
	}
	tailInsert(test,9);  
	printList(test);
	Delete(test,3);
	Delete(test,6); 
	printList(test);
	return 0;
}
