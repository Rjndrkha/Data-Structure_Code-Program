#include <stdio.h>
#include <stdlib.h>

struct student
{
    int rollno;
    struct student *next;
};

void   insertAtEnd(struct student *head){
    struct student *ptr ;
    struct student *temp = (struct student *)malloc(sizeof(struct student));
    ptr = head;
   while(ptr->next != NULL){
       ptr = ptr->next;
   }

   temp->rollno = 0;
   temp->next=NULL;
   ptr->next =temp;

}

void display(struct student *p){

    while (p!=NULL)
    {
        printf("%d ",p->rollno);
        p = p->next;
    }
    
}
int main()
{
    struct student *head = (struct student *)malloc(sizeof(struct student));

    head->rollno = 1;
    head->next = NULL;

    struct student *newstudent = (struct student *)malloc(sizeof(struct student));
    head->next = newstudent;
    newstudent->rollno = 2;
    newstudent->next = NULL;

    newstudent = (struct student *)malloc(sizeof(struct student));

    newstudent->rollno = 3;
    newstudent->next = NULL;

    head->next->next = newstudent;

    insertAtEnd(head);
    insertAtEnd(head);
    insertAtEnd(head);
   
display(head);
    return 0;
}