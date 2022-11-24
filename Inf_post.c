#include <stdio.h>
#include <string.h>
char inf[100];
char stack[100];
char post[100];
int top;

void push(char c){
    top++;
    stack[top]=c;
}

char pop(){
    char ch=stack[top];
    top--;
    return ch; 
}

int oper(char c){
    switch(c){
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void main(){
    top=-1;
    push('(');
    printf("Enter the Infix expression:");
    gets(inf);
    int p=0;
    inf[strlen(inf)]=')';
    for(int i=0;i<=strlen(inf);i++){
        if(inf[i]=='+'||inf[i]=='-'||inf[i]=='*'||inf[i]=='/'||inf[i]=='^'){
            while(oper(inf[i])<=oper(stack[top])){
                post[p]=pop();
                p++;
            }
            push(inf[i]);
        }
        else if(inf[i]=='('){
            push('(');
        }
        else if((inf[i]>='A'&&inf[i]<='Z')||(inf[i]>='a'&&inf[i]<='z')){
            post[p]=inf[i];
            p++;
        }
        else{
            if(inf[i]==')'){
                while(stack[top]!='('){
                    post[p]=pop();
                    p++;
                }
                pop();
            }
        }
    }
    puts(post);
}
