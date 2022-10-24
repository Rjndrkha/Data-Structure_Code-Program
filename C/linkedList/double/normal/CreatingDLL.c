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
    //      forward
while (head !=NULL){
    printf("%d",head->data);
    ptr=head;
    head=head->next;
}
    //      backward
    printf("\n");
    
while (ptr !=NULL){
    printf("%d",ptr->data);
    ptr=ptr->prev;
 
}
}

int main(){
struct node *head = (struct node *) malloc(sizeof(struct node));
head->next=NULL;


struct node *first = (struct node *) malloc(sizeof(struct node));
head->next=first;
first->next=NULL;
first->prev=NULL;
first->data=1;

struct node *second = (struct node *) malloc(sizeof(struct node));
first->next=second;
second->next=NULL;
second->prev=first;
second->data=2;

struct node *third = (struct node *) malloc(sizeof(struct node));
second->next=third;
third->next=NULL;
third->prev=second;
third->data=3;

display(head);
}