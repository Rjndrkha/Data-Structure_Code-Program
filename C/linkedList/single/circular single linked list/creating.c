#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    
};

void display(struct node * head){
    struct node * ptr;
    ptr=head;
    ptr->next; 
    while (ptr != NULL)
    {  
      printf("%d",ptr->data);     
      ptr=ptr->next;
    }
    
}
int main(){
    struct node * head = (struct node *)malloc(sizeof(struct node));
    head->data = NULL;
   
    head->next = NULL;

    struct node * first = (struct node *)malloc(sizeof(struct node));
    head->next = first;
    first->next = head;
    first->data = 1;

    struct node *second = (struct node *)malloc(sizeof(struct node));
    first->next=second;
    second->next=head;
    second->data=2;

    display(head);
   
}