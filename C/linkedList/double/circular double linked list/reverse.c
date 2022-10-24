#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void display(struct node *head)
{
    struct node *trav ;
    trav = head;
    while (trav != NULL)
    {
        printf("%d", trav->data);
        trav = trav->next;
    }
    printf("\n");
}

void addAtEnd(struct node *head, int num)
{

    struct node *trav ;
    trav = head;
    struct node *addAtEnd = (struct node *)malloc(sizeof(struct node));

    while (trav->next != NULL)
    {
        trav = trav->next;
    }

    addAtEnd->data = num;
    trav->next = addAtEnd;
    addAtEnd->prev = trav;
    addAtEnd->next=NULL;

   
}

    struct node * reverse(struct node *head){
        struct node * ptr1 = head;
        struct node *ptr2 = ptr1->next;
       
        
        
        ptr1->next = NULL;
        ptr1->prev =ptr2;

        while (ptr2 !=NULL)
        {
            
            ptr2->prev=ptr2->next;
            ptr2->next=ptr1;

            ptr1=ptr2;
            ptr2=ptr2->prev;
        }
    head = ptr1;
        return head;
        
    }
int main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 0;
    struct node *first = (struct node *)malloc(sizeof(struct node));
    head->next = first;
    first->prev = NULL;
    first->data = 1;
    first->next = NULL;

    addAtEnd(head, 2);
    addAtEnd(head, 3);
    addAtEnd(head, 4);

    printf("after creating \n");
    display(head);
    printf("after reverse \n");
    head = reverse(head);
    display(head);

}