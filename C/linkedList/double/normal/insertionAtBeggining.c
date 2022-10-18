#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};

void display(struct node *head){
    head=head->next;
    struct node* ptr;
   
while (head !=NULL){
    printf("%d",head->data);
    ptr=head;
    head=head->next;
}
}

void  insertionAtbegining(struct node *head,int data,struct node *second)
{
    struct node* first = (struct node *) malloc(sizeof(struct node));
   first->next=second;
   second->prev=first;
   first->data=data;
   head->next=first;
}




int main(){
struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node* second = (struct node *) malloc(sizeof(struct node));
 head->next = second;
 second->data=2;
 second->next=NULL;
 second->prev=head;

int data = 1;
insertionAtbegining(head,65,second);
display(head);
}