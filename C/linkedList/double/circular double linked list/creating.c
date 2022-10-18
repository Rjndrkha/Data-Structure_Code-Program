#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
    
};

void display(struct node * head){
    struct node * ptr;
    ptr=head;
    
    for (int i = 0; i < 10; i++)
    {
        printf("%d",ptr->data);
        ptr=ptr->prev;
    }
    
  
}
int main(){
    struct node * head = (struct node *)malloc(sizeof(struct node));
    head->data = NULL;
    head->prev = NULL;
    head->next = NULL;

    struct node * first = (struct node *)malloc(sizeof(struct node));
    head->next = first;
    head->prev = first;
    first->next = head;
    first->prev = head;
    first->data = 1;

    struct node *second = (struct node *)malloc(sizeof(struct node));
    first->next=second;
    head->prev = second;
    second->next=head;
    second->prev=first;
    second->data=2;

    display(head);
   
}