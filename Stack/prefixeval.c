#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
char pf[100];
float res=0;
float stack[100];
int top=-1;
void push(float p){
    top++;
    stack[top]=p;
    //printf("pushing float %f\t\n",stack[top]);
}
float pop()
{
    if(top<=-1)
    {
        printf("Empty");
        return 0;
    }
    return stack[top--];
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
void eval()
{
    strcpy(pf, reverse(pf));
    float op1,op2;
    int i=0;
    char x;
    while(pf[i]!='\0'){
        x=pf[i];
        if(x>='0' && x<='9'){
            push(x-'0');
        }
        else if(x=='+' || x=='-' || x=='*' || x=='/' || x=='%')
        {
            op1=pop();  //diff heree, already reversed
            op2=pop(); 
            switch(x){
                case '+':
                res=op1+op2;
                break;
                case '-':
                res=op1-op2;
                break;
                case '*':
                res=op1*op2;
                break;
                case '/':
                res=op1/op2;
                break;
                case '%':
                res=(int)op1%(int)op2;
                break;
                
            }
            //printf("\n%f%c%f=%f\n",op1,x,op2,res);
            //printf("Result pushed:");
            push(res);
        }
        else{
            printf("Invalid Expression\n");
            exit(0);
        }
        i++;
    }//end of while
    printf("Result: %f\n", stack[top]);
}
void main(){
    printf("Enter expression: ");
    gets(pf);
    eval();
}