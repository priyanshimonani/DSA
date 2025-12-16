#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
}*start;
void create()
{
int n;
struct node *newnode,*temp;
printf("Enter number of nodes\n");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
if(start==NULL)
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter Data:\n");
scanf("%d",&newnode->data);
start=newnode;
}
else
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter data\n");
scanf("%d",&newnode->data);
temp=start;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}
}
}
void insert_before()
{
struct node *temp,*p,*newnode;
int val,data;
printf("Enter data to insert\n");
scanf("%d",&data);
printf("Enter value before which you want to insert\n");
scanf("%d",&val);
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
temp=start;
p=start;
while(temp->data!=val)
{
    p=temp;
temp=temp->next;
}
if(temp==start)
{
newnode->next=start;
start=newnode;
}
else
{
p->next=newnode;
newnode->next=temp;
}
}
void insert_after()
{
struct node *temp,*post,*newnode;
int val,data;
printf("Enter data to insert\n");
scanf("%d",&data);
printf("Enter value after which you want to insert\n");
scanf("%d",&val);
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
temp=start;
while(temp->data!=val)
{
temp=temp->next;
}
post=temp->next;
temp->next=newnode;
newnode->next=post;
}
void delete1()
{
struct node *p,*temp,*post;
int x;
printf("Enter a value\n");
scanf("%d",&x);
temp=start;
while(temp!=NULL && temp->data!=x)
{
p=temp;
temp=temp->next;
}
if(temp==NULL)
{
printf("Value not found\n");
}
else if(temp==start)
{
start=temp->next;
free(temp);
}
else
{
post=temp->next;
p->next=post;
free(temp);
}
}
void display()
{
int data;
struct node *temp,*next;
temp=start;
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->next;
}
}
void main()
{
int choice;
int exit;
int j;
while(exit!=-1)
{
printf("Enter your choice\n");
printf("1.Create 2.Insert Before 3.Insert After 4.Delete 5.Display 6.Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1: create();
break;
case 2: insert_before();
break;
case 3: insert_after();
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