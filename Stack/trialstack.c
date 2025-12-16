#include <stdio.h>
#include <stdlib.h>
char stack[100], infix[100], postfix[100];
int top=-1;
void push(char ch){
    if(top>=100){
        printf("Stack full");
    }
    else{
        stack[++top]=ch;
    }
    
}
char pop(){
    if(top<=-1){
        printf("Stack Underflow");
        return '0';
    }
    return stack[top--];
}
int priority(char ch){
    if(ch=='+'||ch=='-')
        return 0;
    else if(ch=='*'||ch=='/')
        return 1;
    else
        return -1;
}
void itp(){
    char x;
    int i,j;
    j=0;
    for(i=0;infix[i]!='\0';i++){
        x=infix[i];
        if(x>='A'&& x<='Z'){
            postfix[j++]=x;
        }
        else if(x==')'){
            while(stack[top]!='(')
                postfix[j++]=pop();
            pop();
        }
        else if(x=='(')
            push(x);
        else if(x=='+'||x=='-'||x=='*'||x=='/'||x=='%'){
            if(top==-1)
                push(x);
            else if(priority(x)> priority(stack[top]))
                push(x);
            else{
                while(top!=-1 && priority(x)<=priority(stack[top])){
                    postfix[j++]=pop();
                }
                push(x);
            }
        }
        else if(x!='\n')
            printf("Invalid expression: %c",x);
        
    }//end of for
    while(top!=-1)
            postfix[j++]=pop();
}
void main(){
    printf("Enter expression: ");
    fgets(infix,sizeof(infix),stdin);
    itp();
    int cnt;
    printf("\nPostfix expression: ");
    fflush(stdout);
    for(cnt=0;postfix[cnt]!='\0';cnt++){
        printf("%c",postfix[cnt]);
        fflush(stdout);
    }
}