#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *nextnode;
}*first=NULL;

void display(struct node *p){

    while (p!=NULL)
    {
        printf("%d ",p->data);
        p = p->nextnode;
    }
    
}


int main(){

    struct node *Head =(struct node *) malloc(sizeof(struct node));
    Head->data=1;
    Head->nextnode=NULL;

    struct node *current=(struct node *) malloc(sizeof(struct node));
    Head->nextnode=current;
    current->data=2; 
    current->nextnode = NULL ;

    current=(struct node *) malloc(sizeof(struct node));
    Head->nextnode->nextnode=current;
    current->data=3;
    current->nextnode=NULL;
    display(Head);

    return 0;

}