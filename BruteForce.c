#include <stdio.h>
#include <stdlib.h>

typedef struct String{
	char* data;
	int len; 
}String;
String* initString (){
	String* s = (String*)malloc(sizeof(String));
	s->data=NULL;
	s->len=0;
	return s;
}
void StringAssign(String* s,char* data){
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
		s -> len = 0;
	}else{
		temp = data;
		s -> len = len;
		s -> data = (char*)malloc(sizeof(char*)+(len+1));
		int i;
		for(i=0;i<len;i++,temp++){
			s->data[i] = *temp; 
		}
	}
}
void ForceMatch(String* dom,String* sub){
	int i=0,j=0;
	while(i<dom->len && j<sub->len){
		if(dom->data[i]==sub->data[j]){
			i++;
			j++;
		}
		else{
			i = i - j + 1;
			j = 0;
		}
	}
	if(j == sub->len){
		printf("Force Match Success.\n");
	}
	else{
		printf("Force Match Fail.\n");
	}
}
void Print(String* s){
	int i;
	for(i=0;i<s -> len;i++){
		printf(i==0 ? "%c ":" -> %c",s->data[i]);
	}
	printf("\n");
}
int main(){
	String* mas = initString();
	String* sub = initString();
	StringAssign(mas,"HEELLOO");
	StringAssign(sub,"LO");
	Print(mas);
	Print(sub);
	ForceMatch(mas,sub);
	return 0;
} 
