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
    if(c=='^'){
            return 3;
    }
    else  if(c=='*'||c=='/'){
            return 2;
    } 
    else if(c=='+'||c=='-'){
            return 1;
    }
    else{
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
        if(oper(inf[i])!=0){
            while(oper(inf[i])<=oper(stack[top])){
                post[p]=pop();
                p++;
            }
            push(inf[i]);
        }
        else if(inf[i]=='('){
            push('(');
        }
        else if(isalnum(inf[i])){
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
