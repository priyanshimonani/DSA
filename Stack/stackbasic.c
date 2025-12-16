#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
int stack[10];
int top=-1;
//size 5
void push(){
    int p;
    if(top==4){
        printf("Stack Overflow\n");
    }
    else{
        printf("Enter number to be pushed: ");
        scanf("%d",&p);
        top++;
        stack[top]=p;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("Stack empty");
        fflush(stdout);
        return 0;
    }
    return stack[top--];
}
void peek()
{
    printf("%d\n",stack[top]);
}
void display()
{
    int i;
    printf("\nStack: ");
    for(i=0;i<=top;i++)
        printf("%d ",stack[i]);
}
void main()
{
    int ch=0;
    while (true)
    {
        printf("\n1. Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Invalid Choice!");
        }
    }
}