#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int flag;
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;	
}TreeNode;
typedef struct StackNode{
	TreeNode* data;
	struct StackNode* next;
}StackNode;
void createTree(TreeNode** T,char* data,int* index){
	char ch;
	ch = data[*index];
	*index += 1;
	if(ch == '#'){
		*T = NULL;
	}else{
		*T = (TreeNode*)malloc(sizeof(TreeNode));
		(*T) -> data = ch;
		(*T) -> flag =  0;
		createTree(&((*T)->lchild),data,index);
		createTree(&((*T)->rchild),data,index);		
	}
}
StackNode* initStack(){
	StackNode* S = (StackNode*)malloc(sizeof(StackNode));
	S -> data = NULL;
	S -> next = NULL;
	return S;
}
void push(TreeNode* data,StackNode* S){
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node -> data = data;
	node -> next = S -> next;
	S -> next = node;
}
int isEmpty(StackNode* S){
	if(S -> next == NULL){
		return 1;
	}else{
		return 0;
	}
}
StackNode* pop(StackNode* S){
	if(isEmpty(S)){
		return NULL;
	}else{
		StackNode* node = S -> next;
		S -> next = node -> next;
		return node;
	}
}
StackNode* getTop(StackNode* S){
	if(isEmpty(S)){
		return NULL;
	}else{
		StackNode* node = S -> next;
		return node;
	}
}
void preOrder(TreeNode* T){
	TreeNode* node = T;
	StackNode* S = initStack();
	while(node || !isEmpty(S)){
		if(node){
			printf("%c ",node -> data);
			push(node,S);
			node = node -> lchild;
		}else{
			node = pop(S) -> data;
			node = node -> rchild;
		}
	}
}
void inOrder(TreeNode* T){
	TreeNode* node = T;
	StackNode* S = initStack();
	while(node || !isEmpty(S)){
		if(node){
			push(node,S);
			node = node -> lchild;
		}else{
			node = pop(S) -> data;
			printf("%c ",node -> data);			
			node = node -> rchild;
		}
	}
}
void postOrder(TreeNode* T){
	TreeNode* node = T;
	StackNode* S = initStack();
	while(node || !isEmpty(S)){
		if(node){
			push(node,S);
			node=node->lchild;
		}else{
			TreeNode* top = getTop(S)->data;
			if(top->rchild&&top->rchild->flag==0){
				top = top -> rchild;
				push(top,S);
				node = top -> lchild;
			}else{
				top = pop(S)->data;
				printf("%c ",top->data);
				top->flag = 1;
			}
		}
	}
}
int main(){
	TreeNode* T;
	int index = 0;
	char* tree = "ABD#F##E##C##";
	createTree(&T,tree,&index);
//	preOrder(T);
//	printf("\n");
//	inOrder(T);
//	printf("\n");
	postOrder(T);
	printf("\n");
	return 0;
}
