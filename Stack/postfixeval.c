#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
char pf[100];
float res=0;
float stack[100];
int top=-1;
void push(float p){
    top++;
    stack[top]=p;
    //printf("pushing float %f\t",stack[top]);
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
void eval()
{
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
            op2=pop(); 
            op1=pop(); 
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
            push(res); //forgot thissssssssss
        }
        else{
            printf("Invalid Expression");
            exit(0);
        }
        i++;
    }//end of while
    printf("Result: %f", stack[top]);
    fflush(stdout);
}
void main(){
    printf("Enter expression: ");
    gets(pf);
    eval();
}