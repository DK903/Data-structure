#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node{
	int data;
	struct Node* pre;
	struct Node* next;
}Node;
// 初始化
Node* initList(){
	Node* L = (Node*)malloc(sizeof(Node));
	L -> data = 0;
	L -> pre = NULL;
	L -> next = NULL;
	return L; 
} 
// 头插法 -- 有问题 
void headInsert(Node* L,int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	if(L->data == 0){
		node -> next = L -> next;
		node -> pre = L;
		L -> next = node;
		L -> data++; 
	}else{
		node -> pre = L;
		node -> next = L->next;
		L -> next -> pre = node;
		L -> next = node;
		L->data++;
	}
} 
//尾插法  -- 有问题 
void tailInsert(Node* L,int data){
	Node* node = L;
	Node* n = (Node*)malloc(sizeof(Node));
	n -> data = data;
	while(node->next){
		node = node -> next;
	}
	n -> next = node -> next;
	node -> next = n;
	n -> pre = node;
	L -> data++;
} 
//删除
int Delete(Node* L,int data){
	Node* node = L -> next ;
	while(node){
		if(node->data == data){
			node -> pre -> next = node -> next;
			node -> next -> pre = node -> pre;
			free(node);
			return TRUE;
		}
		node = node->next;
	}
	return FALSE;
} 
//遍历
void printList(Node* L){
	Node* p = L -> next;
	while(p){
		printf("%d -> ",p->data);
	}
	printf("NULL\n");
}
int main(){
	Node* L = initList();
	headInsert(L,1);
	printList(L);
	return 0;
} 
