#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild; 
}TreeNode;
void createTree(TreeNode** T,char* data,int* index){
	char ch;
	ch = data[*index];
	*index += 1;
	if(ch == '#'){
		//此时为空结点 
		*T = NULL;
	}else{
		//此时不为空 
		*T = (TreeNode*)malloc(sizeof(TreeNode));
		(*T) -> data = ch;
		createTree(&((*T)->lchild),data,index);
		createTree(&((*T)->rchild),data,index);		
	}
}
void preOrder(TreeNode* T){
	if(T==NULL){
		return ;
	}else{
		printf("%c ",T -> data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}
void midOrder(TreeNode* T){
	if(T==NULL){
		return ;
	}else{
		midOrder(T->lchild);
		printf("%c ",T -> data);
		midOrder(T->rchild);
	}
}
void postOrder(TreeNode* T){
	if(T==NULL){
		return ;
	}else{
		postOrder(T->lchild);
		postOrder(T->rchild);
		printf("%c ",T -> data);
	}
}
int main(){
	TreeNode* T;
	int index = 0;
	char* tree = "ABD##E##CF##G##";
	createTree(&T,tree,&index);
	printf("先序遍历：");
	preOrder(T);
	printf("\n");
	printf("中序遍历："); 
	midOrder(T);
	printf("\n");
	printf("后序遍历："); 
	postOrder(T);
	printf("\n");
	return 0;
}
