#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    struct node *prev;
    int data;
};
void display(struct node *head)
{
    struct node *disp;
    disp = head;

    while (disp != NULL)
    {
        printf("%d \n", disp->data);
        disp = disp->next;
    }
}
void create(struct node *head)
{
    if (head->next == NULL)
    {
        struct node *first = (struct node *)malloc(sizeof(struct node));
        head->next = first;
        first->prev = head;
        first->next = NULL;
        int data;

        printf("enter the data value");
        scanf("%d", &data);

        first->data = data;
    }
    else
    {
        struct node *trav ;
        trav = head;

        while (trav->next != NULL)
        {
            trav = trav->next;
        }

        struct node *second = (struct node *)malloc(sizeof(struct node));
        second->next = NULL;
        second->prev = trav;
        trav->next = second;
        int data=0;
        printf("enter the data value");
        scanf("%d", &data);
       
        
        second->data = data;
    }
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    head->data = 0;
   
    create(head);
    create(head);
    create(head);
   
   
    display(head);
}