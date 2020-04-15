#include<stdio.h>
#include<string.h>
#define FIN 50


//void pretoin();
char stack[FIN][FIN];int top=-1,i;


void push(char str[]){
	if(top!=FIN-1){
		strcpy(stack[++top],str);
		//printf("%s",stack[top]);	
	}
	else{
		printf("stck is overflow!!!\n");
	}
}

char *pop(){
	char str[FIN];
	if(top!=-1){
		//printf("\t%s",stack[top]);
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
	int len=strlen(str);
	operator[1]='\0';
	while(--len!=-1){
		//printf("%c",str[len]);
		char temp[FIN];	
		if(str[len]==' '){
			continue;
		}
		if(str[len]=='+'||str[len]=='-'||str[len]=='*'||str[len]=='/'||str[len]=='<'||str[len]=='>'||str[len]=='='||str[len]=='('||str[len]==')'){
			strcpy(first,pop());	
			strcpy(second,pop());
			operator[0]=str[len];  //operator
			//printf("\n%s",first);
			//printf("\n%s",second);
			strcpy(temp,first);
			strcat(temp,operator);
			strcat(temp,second);
			push(temp);
		}
		else{
			operator[0]=str[len];  //operands
			push(operator);
		}
	}
	printf("\n%s\n",pop());
	
}

int main(){
	char str[FIN];
	char str1[FIN];
	printf("enter the prefix string\n");
	
	scanf("%s",str);
	//push();
	//pop(str);
	//display();
	pretoin(str,str1);
	//printf("%s\n",str);
	//printf("%s",str1);
	
	return 0;
}




