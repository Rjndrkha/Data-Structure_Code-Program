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

struct node *  insertAtEmpty(int data){
    struct node* first = (struct node *) malloc(sizeof(struct node));
    first->data=data;
    first->next=NULL;
    return first;
}



int main(){
struct node *head = NULL;
int data = 1;
head = insertAtEmpty(data);
printf("%d",head->data);
display(head);
}