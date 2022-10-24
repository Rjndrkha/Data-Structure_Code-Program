#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void display(struct node *head){
    while (head != NULL){
        printf("%d ",head->data);
        head= head->next;
    }
}
struct node * add_at_end(struct node *head , int data){
    
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data=data;
    ptr->next=NULL;
    head->next=ptr;
    return ptr;
}

int main(){
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head->data=1;
    head->next=NULL;

    struct node *ptr = head;

    ptr = add_at_end(ptr,2);
    ptr = add_at_end(ptr,3);
    ptr = add_at_end(ptr,4);
    display(head);
}