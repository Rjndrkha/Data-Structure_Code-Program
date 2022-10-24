#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void display(struct node *head)
{
    struct node *ptr;
    ptr = head;
   
   for (int i = 0; i < 10; i++)
    {
        printf("%d",ptr->data);
        ptr=ptr->prev;
    }
        printf("\n");

}

void insertionAtMid(struct node *head,int poss)
{
    struct node *trav;
    trav = head;
    struct node *insertionAtMid = (struct node *)malloc(sizeof(struct node));
    insertionAtMid->data = 9;
   
    
   for (int i = 0; i < poss; i++)
        {
            trav=trav->next;
        }

        insertionAtMid->next = trav->next;
        insertionAtMid->prev=trav;
        trav->next->prev = insertionAtMid;
        trav->next = insertionAtMid;
    


    
}
int main()
{
    struct node * head ;
    
    struct node *first = (struct node *)malloc(sizeof(struct node));
    head = first;
    first->next = head;
    first->prev=NULL;
    first->data = 1;

    struct node *second = (struct node *)malloc(sizeof(struct node));
    first->next = second;
    second->next = head;
    second->prev=first;
    first->prev=second;
    second->data = 2;

   int poss = 2;
   insertionAtMid(head,poss);
    display(head);
}