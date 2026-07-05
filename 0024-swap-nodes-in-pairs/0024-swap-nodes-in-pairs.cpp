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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp){
            ListNode* kth=temp->next;
            if(kth==NULL){
                if(prevNode) prevNode->next=temp;
                break;
            }
            ListNode* nextNode=kth->next;
            kth->next=NULL;
           ListNode* newHead= reverse(temp);
           if(temp==head){
            head=newHead;
           }
           else{
            prevNode->next=newHead;
           }
           prevNode=temp;
           temp=nextNode;

        }
        return head;
    }
};