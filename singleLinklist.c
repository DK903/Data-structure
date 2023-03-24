#include <stdio.h>
#include <stdlib.h>
// �������ݽṹ 
typedef struct Node {
	int data;
	struct Node* next;
}Node;
//��ʼ������ĺ��� 
Node* initList(){
	Node* list = (Node*)malloc(sizeof(Node));
// list ��ָ��ṹ��Node��ָ�� 
	list -> data = 0;
	list -> next = NULL;
	return list; 
} 
//ͷ�巨 
void headInsert(Node* list, int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	node -> next = list -> next;
	list -> next = node;
	list -> data++;
}
//β�巨
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
//ɾ�� Ĭ�����������ݶ���ͬ 
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
//����
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
