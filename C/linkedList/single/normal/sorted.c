#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *next;
};
struct node * head = NULL;

void sortedAdd(int data){

    struct node *create = (struct node *)malloc(sizeof(struct node));
    create->data = data;
    create->next = NULL;

    if (head == NULL || data < head->data)
    {
        create->next = head;
        head = create;
    }

    else{

        struct node * trav = head;

        while (trav->next != NULL && trav->next->data < data )
        {
            trav= trav->next;
        }
        create->next = trav->next;
        trav->next=create;
        

    }
    
}

void display()
{
    struct node *trav = head;
    while (trav != NULL)
    {
        printf("\n data is : %d", trav->data);
            trav = trav->next;
    }
}

int main()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {   
        int data;
        printf("enter the data : ");
        scanf("%d",&data);
        sortedAdd(data);
    }

    display();
    
}