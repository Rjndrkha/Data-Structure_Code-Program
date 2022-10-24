#include <stdio.h>
#include <stdlib.h>


struct node
{
    // int exponent;
    int  power;
    struct node *next;
};
struct node *head = NULL;




void addAtEnd()
{
    struct node *create = (struct node *)malloc(sizeof(struct node));
    create->next = NULL;

    printf("enter the value of power");
    int power;
    scanf("%d", &power);
    create->power = power;
    



    if (head == NULL )
    {
        
        head = create;
   create->next  = head; }

    if (power < head->power)
    {
        create->next=head;
        // head->next= head->next;
        
        struct node *trav=head;

        while (trav->next!=head)
        {
            /* code */trav=trav->next;
        }
        
        head=create;
        trav->next = head;
        
    }
    
    else
    {
        struct node *trav = head;

        

        while (create->power > trav->next->power && trav->next != head)
        {
            trav = trav->next;
        }

        create->next = trav->next;
        trav->next = create;
    }
}

void display()
{

    struct node *trav = head;

   
            for (int i = 0; i < 10; i++)
            {
              printf("the value of power is : %d \n", trav->power);
              trav = trav->next;
            }
            
       
    
}

int main()
{
    printf("enter the number of terms \n");
    int terms;
    scanf("%d", &terms);

    for (int i = 0; i < terms; i++)
    {
        addAtEnd(head);
    }

    display();
}
