#include <stdio.h>
#include <stdlib.h>
 int c=0;
struct student {
   // char name[];
   int rollno;
   struct student *next;
};

void count(struct student *head){
  struct student *ptr = NULL;
  ptr = head;
   while (ptr != NULL)
   { 
      c++;
      ptr = ptr->next;
   
    }

}

int main(){
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

count(head);
    printf("%d",c);

    return 0  ;

}