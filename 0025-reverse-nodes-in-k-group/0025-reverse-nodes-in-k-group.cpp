/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* find(ListNode* temp,int k){
   k--;
   while(temp && k){
    k--;
    temp=temp->next;
   }
   return temp;
}
ListNode* reverse(ListNode* head){
     ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr){
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        
        while(temp){
            ListNode* kthnode=find(temp,k);
            if(kthnode==NULL){
                if(prevNode!=NULL)
                 prevNode->next=temp;
                break;
            }
            ListNode* nextNode=kthnode->next;
            kthnode->next=NULL;
           ListNode* newhead= reverse(temp);
            if(temp==head)
               head=newhead;
            else{
              prevNode->next=newhead;
              
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};