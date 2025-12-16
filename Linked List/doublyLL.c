#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node *prev, *next;
    int data;
}*root, *temp;
void create(){
    int n,i,x;
    struct Node *nn;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter value: ");
        scanf("%d",&x);
        nn=(struct Node*) malloc(sizeof(struct Node));
        nn->data=x;
        nn->next=NULL;
        if(root==NULL){
            root=nn;
            nn->prev=NULL;
        }
        else{
            temp=root;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=nn;
            nn->prev=temp;
        }
    }
}
void insertbefore(){
    int val,x;
    struct Node *nn,*prev;
    nn=(struct Node*) malloc(sizeof(struct Node));
    printf("Enter value before which node is to be inserted: ");
    scanf("%d",&val);
    printf("Enter value of node: ");
    scanf("%d",&x);
    nn->data=x;
    temp=root;
    while(temp!=NULL && temp->data!=val)
        temp=temp->next;
    if(temp==NULL)
        printf("Vlaue not found");
    else if(temp==root){
        root->prev=nn;
        nn->next=root;
        nn->prev=NULL;
        root=nn;
    }
    else{
        prev=temp->prev;
        prev->next=nn;
        nn->prev=prev;
        nn->next=temp;
        temp->prev=nn;
    }
}
void insertafter(){
    int val,x;
    struct Node *nn,*post;
    nn=(struct Node*) malloc(sizeof(struct Node));
    printf("Enter value after which node is to be inserted: ");
    scanf("%d",&val);
    printf("Enter value of node: ");
    scanf("%d",&x);
    nn->data=x;
    temp=root;
    while(temp!=NULL && temp->data!=val)
        temp=temp->next;
    if(temp==NULL){
        printf("Vlaue not found");
    }
    else{
        post=temp->next;
        temp->next=nn;
        nn->prev=temp;
        nn->next=post;
        if(post!=NULL)
            post->prev=nn;
    }
}
void display(){
    if(root==NULL){
        printf("No elements to display!");
    }
    else{
        temp=root;
        printf("Elements: ");
        while(temp!=NULL){
            printf("%d\t", temp->data);
            temp=temp->next;
        }
    }
}
void delete1(){
    struct Node *pre,*post;
    int x;
    printf("Enter value to be deleted: ");
    scanf("%d", &x);
    temp=root;
    while(temp!=NULL && temp->data!=x){
        temp=temp->next;
    }
    if(temp==root){
        root=root->next;
        root->prev=NULL;
        free(temp);
    }
    else if(temp==NULL){
        printf("Node does not exist");
    }
    else{
        pre=temp->prev;
        post=temp->next;
        pre->next=post;
        if(post!=NULL)
            post->prev=pre;
        free(temp);
    }
}
void main()
{
int choice;
int exit=0;
int j;
while(exit!=-1)
{
printf("\nEnter your choice\n");
printf("1.Create 2.Insert Before 3.Insert After 4.Delete 5.Display 6.Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1: create();
break;
case 2: insertbefore();
break;
case 3: insertafter();
break;
case 4: delete1();
break;
case 5: display();
break;
case 6: exit=-1;
break;
default:
printf("Enter a valid input\n");
break;
}
}
}