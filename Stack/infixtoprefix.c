#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
char stack[100], infixog[100], prefix[100], infixrev[100];
int top = -1;
void push(char p){
    stack[++top] = p;
}
char pop(){
    if(top < 0){
        printf("Stack Underflow\n");
        exit(0);
    }
    return stack[top--];
}
int priority(char op){
    if(op=='+'||op=='-')
        return 0;
    else if(op=='*'||op=='/')
        return 1;
    else if(op=='%')
        return 2;
    return -1;
}
char* reverse(const char og[]){
    static char rev[100];
    int len = strlen(og);

    for(int i=0; i<len; i++){
        rev[i] = og[len-i-1];
        if(rev[i]=='('){
            rev[i]=')';
        }
        else if(rev[i]==')'){
            rev[i]='(';
        }
    }
    rev[len] = '\0';
    return rev;
}
void infixtoprefix(){
    strcpy(infixrev, reverse(infixog));
   // printf("\nReversed infix: %s", infixrev);
    int i=0, j=0;
    while(infixrev[i] != '\0'){
        if(infixrev[i]>='0' && infixrev[i]<='9' || infixrev[i]>='a' && infixrev[i]<='z' || infixrev[i]>='A' && infixrev[i]<='Z'){
            prefix[j++] = infixrev[i];
        }
        else if(infixrev[i]=='+'||infixrev[i]=='-'||infixrev[i]=='*'||infixrev[i]=='/'||infixrev[i]=='%'){
            if(top==-1 || priority(infixrev[i]) >= priority(stack[top])){
                push(infixrev[i]);
            }
            else{
                while(top!=-1 && priority(infixrev[i]) < priority(stack[top])){
                    prefix[j++] = pop();
                }
                push(infixrev[i]); //************
            }
        }
        else if(infixrev[i]=='('){
            push('(');
        }
        else if(infixrev[i]==')'){
            while(top!=-1 && stack[top] != '('){
                prefix[j++] = pop();
            }
            if(top!=-1) pop(); // discard '('
        }
        else{
            printf("\nInvalid input: %c", infixrev[i]);
        }
        i++;
    }
    while(top!=-1){
        prefix[j++] = pop();
    }
    prefix[j] = '\0';

    strcpy(prefix, reverse(prefix));
    printf("\nPrefix Expression: %s\n", prefix);
}
int main(void){
    printf("Enter expression: ");
    gets(infixog);
    infixtoprefix();
    return 0;
}
