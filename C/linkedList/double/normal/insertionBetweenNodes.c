#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node * next;
    struct node * prev;

};

void insertionBwNode(struct node *head,int poss){
    struct node * trav;
    trav=head;
    for (int i = 0; i < poss; i++)
    {
        trav=trav->next;
    }
    
    struct node *third= (struct node *)malloc(sizeof(struct node));
    third->data=3;
    third->next=trav->next;
    third->prev=trav;
    trav->next->prev= third;
    trav->next=third;

    printf("%d",trav->next->data);
}

void display( struct node *head )
{

    struct node *ptr;
    ptr=head;
    while (ptr != NULL)
    {

        ptr = ptr->next;
        printf("%d", ptr->data);
    }
}

int main(){
    struct node *head ;
    head = NULL;

    struct node *first =(struct node *) malloc(sizeof(struct node));
    first->data=1;
    first->next=NULL;
    first->prev=NULL;
    
    head= first;
    
    struct node *second =(struct node *) malloc(sizeof(struct node));
    second->data=2;
    second->next=NULL;
    second->prev=first;

    first->next=second;

    struct node *fourth =(struct node *) malloc(sizeof(struct node));
    fourth->data=4;
    fourth->next=NULL;
    fourth->prev=second;

    second->next=fourth;
    int place =2;
    
    insertionBwNode(head,place);

    display(head);
}