#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *root = NULL, *temp;

void insert(){
    struct Node *nn;
    int val;

    printf("Enter value to be inserted: ");
    scanf("%d", &val);

    nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = val;

    if(root == NULL){
        root = nn;
        nn->next = root;
    }
    else{
        temp = root;
        while(temp->next != root){
            temp = temp->next;
        }
        temp->next = nn;
        nn->next = root;
    }
}

void insert_after(){
    int key, val;
    struct Node *nn;

    if(root == NULL){
        printf("List is empty");
        return;
    }

    printf("Insert after which value: ");
    scanf("%d", &key);

    printf("Enter value to insert: ");
    scanf("%d", &val);

    temp = root;
    while(temp->next != root){
        if(temp->data == key){
            nn = (struct Node*)malloc(sizeof(struct Node));
            nn->data = val;
            nn->next = temp->next;
            temp->next = nn;
            return;
        }
        temp = temp->next;
    }

    if(temp->data == key){
        nn = (struct Node*)malloc(sizeof(struct Node));
        nn->data = val;
        nn->next = temp->next;
        temp->next = nn;
        return;
    }

    printf("Value not found");
}

void insert_before(){
    int key, val;
    struct Node *nn, *prev;

    if(root == NULL){
        printf("List is empty");
        return;
    }

    printf("Insert before which value: ");
    scanf("%d", &key);

    printf("Enter value to insert: ");
    scanf("%d", &val);

    nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = val;

    if(root->data == key){
        temp = root;
        while(temp->next != root){
            temp = temp->next;
        }
        nn->next = root;
        temp->next = nn;
        root = nn;
        return;
    }

    prev = root;
    temp = root->next;

    while(temp != root){
        if(temp->data == key){
            prev->next = nn;
            nn->next = temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Value not found");
    free(nn);
}

void delete1(){
    struct Node *prev, *last;
    int val;

    if(root == NULL){
        printf("List is empty");
        return;
    }

    printf("Enter value to be deleted: ");
    scanf("%d", &val);

    if(root->next == root && root->data == val){
        free(root);
        root = NULL;
        return;
    }

    if(root->data == val){
        last = root;
        while(last->next != root){
            last = last->next;
        }
        last->next = root->next;
        temp = root;
        root = root->next;
        free(temp);
        return;
    }

    prev = root;
    temp = root->next;

    while(temp != root){
        if(temp->data == val){
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Value not found");
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

void main(){
    int ch = 0;

    printf("\n1.Insert");
    printf("\n2.Display");
    printf("\n3.Delete");
    printf("\n4.Insert After");
    printf("\n5.Insert Before");
    printf("\n-1.Exit");

    while(ch != -1){
        printf("\nEnter choice: ");
        scanf("%d", &ch);

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
            case 4:
                insert_after();
                break;
            case 5:
                insert_before();
                break;
            case -1:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice");
        }
    }
}
