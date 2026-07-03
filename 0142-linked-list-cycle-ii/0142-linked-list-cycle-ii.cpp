/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
          ListNode* fast=head;
          while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            ListNode* entry=head;
            if(slow==fast){
                while(entry!=slow){
                    entry=entry->next;
                    slow=slow->next;
                }
                return entry;
            }
          }
        
        return NULL;
    }
};