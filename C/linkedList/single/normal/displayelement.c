#include <stdio.h>
#include <stdlib.h>

struct student {
   char name[];
   int rollno;
   struct student *next;
};

void print(){

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


}