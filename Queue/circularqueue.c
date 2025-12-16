#define size 5
#include <stdio.h>
#include <conio.h>
int cqueue[5];
int front=-1, rear=-1;
void enqueue(int x){
    if(front==-1){
        front=0;
        rear=0;
        cqueue[rear]=x;
    }
    else if((rear+1)%size==front){
        printf("Queue Full");
    }
    else{
        rear=(rear+1)%size;
        cqueue[rear]=x;
    }
}
void dequeue(){
    int val;
    if(front==-1){
        printf("Queue Empty\n");
    }
    else if((front+1)%size==rear){
        printf("Deleted %d\n", cqueue[front]);
        front=-1;
        rear=-1;
    }
    else{
printf("Deleted %d\n", cqueue[front]);
        front=(front+1)%size;
    }
}
void display(){
    int i;
    if (front==-1){
        printf("Queue Empty\n");
    }
    else{
        printf("Elements: ");
        for(i=front;i!=rear;i=(i+1)%size){
           printf("%d, ",cqueue[i]);
        }
        printf("%d\n", cqueue[rear]);
    }   
}
void main(){
    int ch=0,add;
    printf("1. Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    while(ch!=4){
        printf("\n\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter value to be added: ");
            scanf("%d",&add);
            enqueue(add);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            break;
            default:
            printf("Invalid Input\n");
        }
    }
}