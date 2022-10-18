#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *nextnode;
};

void display(struct node *p)
{

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->nextnode;
    }
}
void at_position(struct node *head, int position, int data)
{
    struct node *ptr = head;

    struct node *block = (struct node *)malloc(sizeof(struct node));
    block->data = data;
    block->nextnode = NULL;

    for (int i = 1; i < position; i++)
    {
        ptr = ptr->nextnode;
    }

    block->nextnode = ptr->nextnode;
    ptr->nextnode = block;
}

int main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->nextnode = NULL;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    head->nextnode = newnode;
    newnode->data = 2;
    newnode->nextnode = NULL;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = 3;
    newnode->nextnode = NULL;

    head->nextnode->nextnode = newnode;

    at_position(head, 1, 122);
    at_position(head, 2, 222);
    at_position(head, 3, 322);
    display(head);

    return 0;
}