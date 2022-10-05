// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.
class Solution {
public:
    ListNode* merge(ListNode* a,ListNode* b){
        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }
        ListNode* x=new ListNode(0);
        ListNode* t=x;
        while(a && b){
            if(a->val<b->val){
                t->next=a;
                t=t->next;
                a=a->next;
            }
            else{
                t->next=b;
                b=b->next;
                t=t->next;
            }
        }
        if(a){
            t->next=a;
        }
        if(b){
            t->next=b;
        }
        return x->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        for(int i=1;i<lists.size();i++){
            if(lists[i]!=NULL){
                  lists[0]=merge(lists[0],lists[i]);
            }
          
        }
        return lists[0];
    }
};
