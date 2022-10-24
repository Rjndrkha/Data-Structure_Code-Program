#include <stdio.h>
#include <stdlib.h>
struct node *head = NULL;

struct node
{
    int exponent, power;
    struct node *next;
};

void create()
{
    struct node *create = (struct node *)malloc(sizeof(struct node));
    head = create;
    create->next = head;

    printf("enter the value of exponent");
    int exponent;
    scanf("%d", &exponent);
    create->exponent = exponent;

    printf("enter the value of power");
    int power;
    scanf("%d", &power);
    create->power = power;
}

void addAtEnd()
{
    if (head == NULL)
    {
        create();
    }

    else
    {
        struct node *trav1,*trav2 = head;

        // creating a node
        struct node *create = (struct node *)malloc(sizeof(struct node));
        printf("enter the value of exponent");
        int exponent;
        scanf("%d", &exponent);
        create->exponent = exponent;

        printf("enter the value of power");
        int power;
        scanf("%d", &power);
        create->power = power;


 if(create->power <= head->power){
     create->next = head;
     head = create;
 }

 else{
     while (create->power > trav1->next->power && trav1->next != head)
     {
         trav1 = trav1->next;
     }

     create->next = trav1;
     trav1->next = create;

 }
}
}
void display(){


            struct node *trav = head;

            while (trav->next != head)
            {

                printf("the value of power is : %d \n",trav->power);
                printf("the value of exponent is : %d \n",trav->exponent);


                trav = trav->next ;
            }



}

int main()
{
    printf("enter the number of terms \n");
    int terms ;
    scanf("%d", &terms);

    for (int i = 0; i < 5; i++)
    {
        addAtEnd(head);
    }

    display();
}
