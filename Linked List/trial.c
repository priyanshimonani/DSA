#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*root, *temp;
void insert(){
    struct Node *nn, *tail;
    int val, n;

    printf("Enter number of nodes to be inserted: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter value to be inserted: ");
        scanf("%d", &val);

        nn = (struct Node*) malloc(sizeof(struct Node));
        nn->data = val;

        if(root == NULL){
            root = nn;
            tail = nn; 
        }
        else{
            tail->next = nn;
            tail = nn;
        }
        nn->next = root;
    }
}
void display(){
    if(root==NULL){
        printf("No elements to display");
    }
    else{
        temp=root;
        while(temp->next!=root){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
         printf("%d\t",temp->data);
    }
}
void delete1(){
    struct Node *prev;
    prev=root;
    int val;
    printf("Enter value to be deleted: ");
    scanf("%d",&val);
    if(root->data==val){
        temp=root->next;
        while(temp!=root){ //connecting last to root
            temp=temp->next;
        }
        temp->next=root->next;
        free(root);
        root=temp->next;
    }
    else{
        temp=root->next;
        while(temp!=root && temp->data!=val){
            prev=temp;
            temp=temp->next;
        }
        if(temp==root){
            printf("Value doesnt exist");
        }
        else{
            prev->next=temp->next;
            free(temp);
        }
    }
}
void main(){
    int ch=0;
    printf("1.Insert\n2.Display\n3.Delete");
    while(ch!=-1){
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insert();
            break;
            case 2:
            display();
            break;
            case 3:
            delete1();
            break;
            case -1:
            printf("Exiting...");
            break;
            default:
            printf("Invalid Input");
        }
    }
}