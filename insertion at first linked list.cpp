#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
void push(Node**head_ref,int new_data){
    Node* new_node= new Node();
    new_node->data= new_data;
    new_node->next= (*head_ref);
    (*head_ref)=new_node;
}
void printlist(Node* n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
}
int main(){
    Node* Head= NULL;
    Node* Second= NULL;
    Node* third= NULL;
    Head= new Node;
    Second= new Node;
    third= new Node;
    Head->data=1;
    Head->next=Second;
    Second->data=2;
Second->next=third;
third->data=3;
third->next=NULL;
push(&Head,7);
printlist(Head);
}