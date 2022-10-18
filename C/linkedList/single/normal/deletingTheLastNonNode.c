#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;

};
void display(struct node *head){
    while (head != NULL){
        printf("%d ",head->data);
        head= head->next;
    }
}
void insertNext(struct node *ptr1){
    struct node * ptr2 ;
    ptr2 = ptr1;
    struct node * newElement = (struct node *) malloc(sizeof(struct node));
    newElement->data=6;
    newElement->next=NULL;

    while (ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
        
    } 
    ptr2->next=newElement;

}

int main(){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data =0;
    head->next = NULL;

    struct node *one = (struct node *)malloc(sizeof(struct node));

    head->next = one;
    one->data =1;
    one->next = NULL;

    insertNext(head);  
    display(head);
}