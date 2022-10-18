#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *next;
};


struct node *  sortedAdd(struct node * head ,int data){

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

    return head;
    
}

void display(struct node * head)
{
    struct node *trav = head;
    
    while (trav != NULL)
    {
        printf("\n data is : %d", trav->data);
            trav = trav->next;
    }
}

struct node * create(struct node * h){
    struct node * head =(struct node *) malloc(sizeof(struct node));
    
    head = NULL;
    int n = 5;
    printf("enter the number of terms : ");

    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {   
        int data;
        printf("enter the data : ");
        scanf("%d",&data);
       head =  sortedAdd(head,data);
    }

    return head;
}

struct node * add(struct node *list1, struct node *list2){

    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->next = NULL;

    struct node *trav = new;
    while (list1 != NULL && list2 != NULL)
    {

    struct node *node = (struct node *)malloc(sizeof(struct node));
        trav->next = node;
        node->next = NULL;

        if (list1->data < list2->data)
        {
            node->data = list1->data;
            list1 = list1->next;

        } 
        else if (list1->data > list2->data)
        {
            node->data = list2->data;
            list2 = list2->next;

        }

        else if (list1->data == list2->data)
        {
            node->data = list2->data;
            list2 = list2->next;

        

        }
        
        trav=trav->next;
    }
    while (list1 != NULL)
    {struct node *node = (struct node *)malloc(sizeof(struct node));
        trav->next = node;
        node->next = NULL;
       node->data = list1->data;
            list1 = list1->next;
            trav = trav->next;
    }while (list2 != NULL)
    {struct node *node = (struct node *)malloc(sizeof(struct node));
        trav->next = node;
        node->next = NULL;
       node->data = list2->data;
            list2 = list2->next;
            trav = trav->next;
    }
    new = new->next;
    return new;
    

}
int main()
{
    struct node *list1 = (struct node *)malloc(sizeof(struct node));
    list1 = create(list1);
    // display(list1);
    
    struct node *list2 = (struct node *)malloc(sizeof(struct node));
    list2 = create(list2);
    // display(list2);

    struct node *newlist = (struct node *)malloc(sizeof(struct node));
     
    newlist = add(list1,list2);
    
    display(newlist);
    
}