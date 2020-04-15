#include<stdio.h>
#include<string.h>
#define FIN 50
char stack[FIN][FIN];int top=-1,i;


void push(char str[]){
	if(top!=FIN-1){
		strcpy(stack[++top],str);
	}
	else{
		printf("stck is overflow!!!\n");
	}	
}

char *pop(){
	char str[FIN];
	if(top!=-1){
		return (stack[top--]);
	}
	else{
		printf("stack is underflow\n");
	}
}

void pretoin(char str[],char str1[]){
	char operator[2];
	char first[FIN];
	char second[FIN];
	int len1=strlen(str),len = 0;
	operator[1]='\0';
	while(len<len1){
		//printf("%c",str[len]);
		char temp[FIN];	
		if(str[len]==' '){
			continue;
		}
		if(str[len]=='+'||str[len]=='-'||str[len]=='*'||str[len]=='/'||str[len]=='<'||str[len]=='>'||str[len]=='='||str[len]=='('||str[len]==')'){
			strcpy(first,pop());	
			strcpy(second,pop());
			operator[0]=str[len];  //operator
			strcpy(temp,second);
			strcat(temp,operator);
			strcat(temp,first);
			push(temp);
		}
		else{
			operator[0]=str[len];  //operands
			push(operator);
		}len++;
	}
	printf("\n%s\n",pop());
	
}

int main(){
	char str[FIN];
	char str1[FIN];
	printf("enter the postfix string\n");
	scanf("%s",str);
	pretoin(str,str1);
	return 0;
}




