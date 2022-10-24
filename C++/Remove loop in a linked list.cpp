//Problem link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1?page=1&category[]=Linked%20List&category[]=Stack&sortBy=submissions



class Solution
{
    public:
   
    void removeLoop(Node* head)
    {
        
       Node* sptr=head->next;
       Node* fptr=head->next->next;
       while(fptr!=sptr){
           if(fptr==NULL||fptr->next==NULL){
               return;
               
           }
           fptr=fptr->next->next;
           sptr=sptr->next;
       }
       sptr=head;
       Node* prev=fptr;
       if(fptr==head){
           prev=head->next;
           while(prev->next!=head)
               prev=prev->next;
               prev->next=NULL;
               return ;
       }
       while(sptr!=fptr){
           sptr=sptr->next;
           prev=fptr;
           fptr=fptr->next;
       }
       prev->next=NULL;
    
    }
};