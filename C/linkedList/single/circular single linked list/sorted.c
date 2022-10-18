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
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void sortedInsert(struct node *head, int data)
{
    struct node *trav;
    trav = head;
    struct node *sortedinsert = (struct node *)malloc(sizeof(struct node));
    sortedinsert->data = data;
    sortedinsert->next = NULL;

    if (head == NULL || data < trav->data)
    {

        sortedinsert->next = head;
        head = sortedinsert;
    }
    else
    {

        while (trav->next != NULL && trav->next->data < data && trav->next != head)
        {
            trav = trav->next;
        }

        sortedinsert->next = trav->next;
        trav->next = sortedinsert;
    }
}

   
int main()
{
    struct node *head;

    struct node *first = (struct node *)malloc(sizeof(struct node));
    head = first;
    first->next = head;
    first->data = 1;

    struct node *second = (struct node *)malloc(sizeof(struct node));
    first->next = second;
    second->next = head;
    second->data = 2;
    display(head);
    int data = 3;
    sortedInsert(head, data);
    display(head);
}