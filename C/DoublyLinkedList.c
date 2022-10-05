#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

//function to implement the header nide
struct node* addToEmpty(struct node* head, int data) {
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
};

//function to add other nodes
struct node* addAtEnd(struct node* head, int data) {
    struct node* temp, *tp;
    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    tp = head;
    
    while (tp->next != NULL) {
        tp = tp->next;
        }
        tp->next = temp;
        temp->prev = tp;
        return head;
    };

//function to delete the header node
struct node* delFirst(struct node* head) {
    struct node* temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    head->prev = NULL;
    return head;
    };

//function to add a node in between another node
struct node* addAfterPos(struct node* head, int data, int position) {
    struct node* newP = NULL;
    struct node* temp = head;
    struct node* temp2 = NULL;
    newP = addToEmpty(newP, data);
    
    while (position != 1) {
        temp = temp->next;
        position --;
        }
        
        if(temp->next == NULL) {
            temp->next = newP;
            newP->prev = temp;
            } else {
                temp2 = temp->next;
                temp->next = newP;
                temp2->prev = newP;
                newP->next = temp2;
                newP->prev = temp;
            }
            return head;
            };

//funtion to swap the header node with another node
struct node* swapVal (struct node*hd) {
    struct node* ptr = hd;
    if (hd == NULL) {
        printf("No data in List");
        } else {
            hd = hd->next;
            ptr->next = hd->next;
            hd->next = ptr;
            hd->prev = NULL;
            ptr->prev = hd;
            ptr->next->prev = ptr;
        }
        return hd;
        };

//function to print
void print(struct node* hd2) {
    struct node* ptr;
    ptr = hd2;
    if (hd2 == NULL) {
        printf("No data in List");
    } else {
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    
    printf("\n");
};

int main () {
    struct node* head = NULL;
    struct node* ptr2;
    int position = 2;
    
//store the node values
head = addToEmpty(head, 5);
head = addAtEnd(head, 6);
head = addAtEnd(head, 9);
head = addAtEnd(head, 0);
head = addAtEnd(head, 1);
printf("The Initial Doubly Linked List: \n");
print(head);
head = delFirst(head);
printf("The Doubly Linked List After Deleting the Head Node: \n");
print(head);
head = addAfterPos(head, 10, position);
printf("The Doubly Linked List After Adding 10: \n");
print(head);
printf("\n");
printf("The Final Doubly Linked List:\n");
head = swapVal(head);
print(head);
return 0;
}
