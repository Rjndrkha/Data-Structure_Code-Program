#include <stdio.h>
#include <stdlib.h>
struct student{
   int rollno;
   struct student *next;
};

void display(struct student *head){
    while (head != NULL){
        printf("%d ",head->rollno);
        head= head->next;
    }
}

struct student * deleteFirst(struct student * head ){
   struct stdent * del =head;
 head = head->next;
 free(del);
    return head;
}
int main (){
    struct student *head =(struct student *) malloc(sizeof( struct student));

 head->rollno=0;
 head->next =NULL;

struct student *one = (struct student *) malloc(sizeof( struct student));
 head->next = one;
 one->rollno=2;
 one->next = NULL;
 struct student *second = (struct student *) malloc(sizeof( struct student));
 one->next = second;
 second->rollno=2;
 second->next = NULL;
 
 head =   deleteFirst(head);
 
    display(head);
    display(head);
 
        
    

 }