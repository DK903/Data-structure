#include <stdio.h>
#include <stdlib.h>

#define TURE 1
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
	L -> pre = L;
	L -> next = L;
	return L;
}
// 头插法 
void headInsert(Node* L,int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	if(L -> data == 0){
		node -> pre = L;
		node -> next = L -> next;
		L -> next = node;
		L -> pre = node; 
		L -> data++;
	}
	else{ // 链表不为空 
		node -> next = L -> next;
		node -> pre = L;
		L -> next -> pre = node;
		L -> next = node;
		L -> data++;
	}
	//L -> data++;
}
// 尾插法
void tailInsert(Node* L,int data){
	Node* node = L;
	while(node -> next != L){
		node = node -> next;
	}
	Node* n = (Node*)malloc(sizeof(Node));
	n -> data = data;
	n -> pre = node;
	n -> next = L;
	L -> pre = n;
	node -> next = n;
} 
//删除
int Delete(Node* L,int data){
	Node* node = L -> next;
	while(node!=L){
		if(node->data == data){
			node->pre->next = node->next;
			node->next->pre = node->pre;
			free(node);
			L->data--;
			return TURE;
		}
		node = node -> next;
	}
	return FALSE;
}
// 遍历
void printList(Node* L){
	Node* node = L -> next;
	while(node != L){
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("NULL\n");
}
int main(){
	Node* L =  initList();
	headInsert(L,1); 
	headInsert(L,2);
	headInsert(L,3);
	headInsert(L,4);
	printList(L);
	tailInsert(L,6);
	tailInsert(L,7);
	printList(L);
	Delete(L,2);
	Delete(L,5);
	printList(L);
	return 0;
}
