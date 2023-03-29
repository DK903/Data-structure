#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
typedef struct String{
	char* data;
	int len;
}String;

String* initString(){
	String* s = (String*)malloc(sizeof(String));
	s -> data = NULL;
	s -> len  = 0; 
	return s;
}
void stringAssign(String* s,char* data){
	if(s->data){
		free(s->data);
	}
	int len =0;
	char* temp = data;
	while(*temp){
		len++;
		temp++;
	}
	if(len == 0){
		s -> data = NULL;
		s -> len  = 0;
	}
	else{
		int i ;
		temp = data;
		s ->len = len;
		s -> data = (char*)malloc(sizeof(char)*(len+1));
		for(i = 0;i<s->len;i++,temp++){
			s->data[i] = *temp;
		}
	}
}
int* getNext(String* s){
	int* next = (int*)malloc(sizeof(int)* s->len);
	int i = 0;
	int j = -1;
	next[i] = j;
	while(i < s->len -1){
		if(j==-1||s->data[i] == s->data[j]){
			i++;
			j++;
			next[i] = j;
		}else{
			j = next[j];
		}
	}
	return next;
}
void Print_next(int* next,int len){
	int i = 0;
	for(i=0;i<len;i++){
		printf(i==0? "%d":" -> %d",next[i]);
	}
	printf("\n");
}
void Print(String* s){
	int i;
	for(i=0;i<s->len;i++){
		printf(i==0? " %c":" -> %c",s->data[i]);
	}
	printf("\n");
}
void kmpMatch(String* master,String* sub,int* next){
	int i = 0;
	int j = 0;
	while(i < master->len && j < sub->len){
		if( j==-1 || master->data[i] == sub->data[j]){
			i++;
			j++;
		}else{
			j = next[j];
		}
	}
	if( j == sub -> len){
		printf("kmp match success. \n");
	}else{
		printf("kmp match fail.\n");
	}
}
int main(){
	printf("-----------欢迎使用KMP算法-----------\n");
	char* master = "abababababc";
	char* sub    = "ababc";
	//scanf("%s",&ch);
	//printf("%c\n",ch);
	String* s = initString();
	String* s1 = initString();
	stringAssign(s,master);
	stringAssign(s1,sub);
	int* next = getNext(s1);
	Print(s);
	Print(s1);
	Print_next(next,s1->len);
	kmpMatch(s,s1,next);
	return 0;
} 
