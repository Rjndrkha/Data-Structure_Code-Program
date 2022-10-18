#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *nextnode;
};

void display(struct node *p){

    while (p!=NULL)
    {
        printf("%d ",p->data);
        p = p->nextnode;
    }
    
}
struct node * at_beg(struct node *head, int data){

struct node *block= (struct node *) malloc(sizeof(struct node));
block->data = data;
block->nextnode=NULL;

block->nextnode = *head;

return block;


}

int main(){struct node *head = (struct node *)malloc(sizeof(struct node));

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

  head = at_beg(head,0);
  head = at_beg(head,1);
  head = at_beg(head,3);
   
display(head);

return 0;
}