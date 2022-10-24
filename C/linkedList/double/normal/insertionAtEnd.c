#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void insertAtEnd(struct node *head)
{
    struct node *trav;
    trav = head;
    struct node *end = (struct node *)malloc(sizeof(struct node));

    while (trav->next != NULL)
    {
        trav = trav->next;
    }
    end->data = 3;
    end->next = NULL;
    trav->next = end;
    end->prev = trav;
}
void display( struct node *head )
{

    struct node *ptr;

    while (head != NULL)
    {

        head = head->next;
        printf("%d", head->data);
    }
}
int main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));

    head->data = 0;
    head->prev = NULL;
    head->next = NULL;

    struct node *first = (struct node *)malloc(sizeof(struct node));
    head->next = first;
    first->data = 1;
    first->next = NULL;
    first->prev = head;

    struct node *second = (struct node *)malloc(sizeof(struct node));
    first->next = second;
    second->data = 2;
    second->next = NULL;
    second->prev = first;

    insertAtEnd(head);
    
    display(head);
}