#include <stdio.h>
#include <stdlib.h>
// 定义数据结构 
typedef struct Node {
	int data;
	struct Node* next;
}Node;
//初始化链表的函数 
Node* initList(){
	Node* list = (Node*)malloc(sizeof(Node));
// list 是指向结构体Node的指针 
	list -> data = 0;
	list -> next = NULL;
	return list; 
} 
//头插法 
void headInsert(Node* list, int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	node -> next = list -> next;
	list -> next = node;
	list -> data++;
}
//尾插法
void tailInsert(Node* list,int data){
	Node* head = list;
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	node -> next = NULL;
	list = list -> next;
	while(list->next){
		list = list -> next;
	}
	list -> next = node;
	head -> data++;
}
//删除 默认链表中数据都不同 
void Delete(Node* list, int data){
	Node* pre = list;
	Node* current = list -> next;
	while(current){
		if(current -> data == data){
			pre -> next = current -> next;
			free(current);
			break;
		}
		pre = current;
		current = current -> next;
	}
	list -> data--;
} 
//遍历
void printList(Node* list){
	list = list -> next;
	while(list){
		printf("%d ",list->data);
		list = list->next;
	}
	printf("\n");
} 
int main(){
	Node* test = initList();
	for(int i=0;i<5;i++){
		headInsert(test,i);
	}
	for(int i=5;i<9;i++){
		tailInsert(test,i);
	}
	Delete(test,3);
	printList(test);
	
	return 0;
} 
