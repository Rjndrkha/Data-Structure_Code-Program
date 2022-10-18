#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void display(struct node *head)
{   struct node *ptr=head;
   
    

    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
     
        ptr = ptr->next;
    }
    printf("\n");
}

struct node* reverse(struct node *head)
{
    struct node *ptr1 = head;
    struct node *ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;
    while (ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;

    struct node *first = (struct node *)malloc(sizeof(struct node));
    head->next = first;
    first->next = NULL;
    first->prev = NULL;
    first->data = 1;

    struct node *second = (struct node *)malloc(sizeof(struct node));
    first->next = second;
    second->next = NULL;
    second->prev = first;
    second->data = 2;

    struct node *third = (struct node *)malloc(sizeof(struct node));
    second->next = third;
    third->next = NULL;
    third->prev = second;
    third->data = 3;

    display(head);

    head = reverse(head);
    

    display(head);
}