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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head;
         int len = 0;
    ListNode* temp = head;

    while (temp) {
        len++;
        temp = temp->next;
    }
    k=k%len;
    if(k==0) return head;
        for(int i=0;i<k;i++){
            fast=fast->next;
        }
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode* temp1=head;
        head=slow->next;
        slow->next=NULL;
        fast->next=temp1;
        return head;
    }
};