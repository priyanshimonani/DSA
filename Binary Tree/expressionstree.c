#include <stdio.h>
#include <stdlib.h>
struct Node{
    char data;
    struct Node *right, *left;
};
struct Node *stack[100];
int top=-1;
void push(struct Node *temp){
    stack[++top]=temp;
}
struct Node* pop(){
    return stack[top--];
}
char pf[100];
void create(){
    struct Node *nn;
    int i=0;
    char x;
    while(pf[i]!='\0'){
        x=pf[i];
        nn=(struct Node*) malloc(sizeof(struct Node));
        nn->data=x;
        if(x=='+' || x=='-' || x=='*' || x=='/' || x=='%'){ 
            nn->right=pop();
            nn->left=pop();
            push(nn);
        }
        else{
            nn->right=NULL;
            nn->left=NULL;
            push(nn);
        }
        i++;
    }
}
void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root){
    if(root!=NULL){
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

void main(){
    struct Node *root;
    printf("Enter postfix expression: ");
    scanf("%s", pf);

    create();
    root = pop();

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);
}
