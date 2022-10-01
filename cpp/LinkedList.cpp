#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node* prev;
};
struct node *printList(struct node* n, struct node* last);
//struct node* deletion(struct node* n, int n0);
int main()
{
    node* head = (struct node*)malloc(sizeof(struct node));
    node* n1 = (struct node*)malloc(sizeof(struct node));
    node* n2 = (struct node*)malloc(sizeof(struct node));
    node* n3 = (struct node*)malloc(sizeof(struct node));
    node* last = (struct node*)malloc(sizeof(struct node));

    head -> data = 1;
    n1 -> data = 2;
    n2 -> data = 3;
    n3 -> data = 4;
    last -> data = 5;

    head -> next = n1;
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = last;
    last -> next = head;

    head -> prev = last;
    n1 -> prev = head;
    n2 -> prev = n1;
    n3 -> prev = n2;
    last -> prev = n3;

    head = printList(head, last);
    return 0;
}
struct node *printList(struct node* head, struct node* last){
    struct node* n = head;
    do{
        printf("%d ",n -> data);
        n = n -> next;
    }while(n != last);
    struct node* m = (struct node*)malloc(sizeof(struct node));
     m = n;
    printf("%d", m -> data);

    printf("\n");
    return head;

void insertion(struct node* head){
    struct node* m = head;
}
