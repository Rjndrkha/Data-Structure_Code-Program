//traverse
//insert at beg,end,mid
//delete at beg,end,mid

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data; 
    Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
void printList(Node* head)
{
    if(head==NULL)

{
    cout<<"empty hai list !";
}   
 Node* t=head;
   do{
       cout<<t->data<<"->";
        t=t->next;

    }while(t!=head);
    cout<<"\n";
}
Node* insertatbeg(Node* head,Node* tail,int i)//or by getting only head as para,swap the data :)
{
    Node* t =new Node(i);
    if(head==NULL)
    { t->next=t;
        return t;
    }
    else{
        tail->next=t;
        t->next=head;
        head=t;
        return head;
        
    }
} 
Node* insertatend(Node *head,int i)//o{1} tc
{
    Node* temp=NULL;
    temp=new Node(i);
    if(head==NULL)
    {temp->next=temp;
        return temp;
    }
   Node* cur=head;
   
    do
    {
        cur=cur->next;
    }while(cur->next!=head);
   cur->next=temp;
   temp->next=head;
   return head;
} 
Node* delatk(Node* head,int k)
{
if(head==NULL)
{
    return head;
}
else
{
    int c=1;
    Node*t =head;
    while(c<(k-1))
    {
        t=t->next;
        c++;
    }
    Node* tt=t->next;;
    
        t->next=tt->next;
        delete tt;
    return head;
}
}
int main()
{
Node* head=new Node(1);
head->next=new Node(2);
head->next->next=new Node(3);
Node* tail=head->next->next;
tail->next=head;
printList(head);
head=insertatbeg(head,tail,7);
head=insertatend(head,9);
printList(head);
head=delatk(head,2);
head=delatk(head,6);
printList(head);
}
