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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=NULL;
        while(slow){
            ListNode* next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }
      ListNode* f=head;
      ListNode* s=prev;
      while(f && s){
        if(f->val!=s->val) return false;
        f=f->next;
        s=s->next;
      }
        return true;
    }
};