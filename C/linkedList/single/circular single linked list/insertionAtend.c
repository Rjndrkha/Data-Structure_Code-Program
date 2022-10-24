#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    struct node *ptr;
    ptr = head;
   
   for (int i = 0; i < 10; i++)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
        printf("\n");

}

void insertionAtEnd(struct node *head)
{
    struct node *trav;
    trav = head;
    struct node *insertionAtEnd = (struct node *)malloc(sizeof(struct node));
    insertionAtEnd->data = 9;
   
    
        while (trav->next != head)
        {
            trav=trav->next;
        }
        insertionAtEnd->next = trav->next;
        trav->next = insertionAtEnd;

    
}
int main()
{
    struct node * head ;
    
    struct node *first = (struct node *)malloc(sizeof(struct node));
    head = first;
    first->next = head;
    first->data = 1;

    struct node *second = (struct node *)malloc(sizeof(struct node));
    first->next = second;
    second->next = head;
    second->data = 2;

   
   insertionAtEnd(head);
    display(head);
}