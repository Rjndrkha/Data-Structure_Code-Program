#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *nextnode;
};

int main(){

    // //              Method 1
    // struct node *Head =(struct node *) malloc(sizeof(struct node));
    // Head->data=1;
    // Head->nextnode=NULL;

    // struct node *Second=(struct node *) malloc(sizeof(struct node));
    // Head->nextnode=Second;
    // Second->data=2; 
    // Second->nextnode = NULL ;

    // printf("%d\n",Head->data) ; 
    // printf("%d",Second->data);


    //                    Method 2

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

    printf("%d",current->data);
}