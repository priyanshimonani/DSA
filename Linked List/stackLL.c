#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*top;
void push(){
    struct Node *nn;
    nn=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to be inserted: ");
    scanf("%d",&nn->data);
    nn->next=top;
    top=nn;
}
int pop(){
    if(top==NULL){
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node *temp;
    int val=top->data;
    temp=top;
    top=top->next;
    free(temp);
    return val;
}
int peek(){
    return top->data;
}
void display(){
    if(top==NULL){
        printf("No Elements to display");
    }
    else{
        printf("Elements: ");
        struct Node *temp;
        temp=top;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
void main(){
    int ch=0;
    while(ch!=-1){
        printf("\n\n1.Push\n2.Pop\n3.Peek\n4.Display\n-1.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
            push();
            break;
            case 2: 
            printf("Popped value: %d",pop());
            break;
            case 3:
            printf("Top value: %d",peek());
            break;
            case 4: display();
            break;
            case -1:
            printf("Exiting");
            break;
            default:
            printf("Invalid input");
        }
    }
}