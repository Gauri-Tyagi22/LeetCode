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
 class cmp{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* ,vector<ListNode*>,cmp>pq;
        for(ListNode* head:lists){
            if(head!=NULL)
              pq.push(head);
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(!pq.empty()){
            ListNode* curr=pq.top();
            pq.pop();
            temp->next=curr;
            temp=temp->next;
            if(curr->next!=NULL) pq.push(curr->next);
        }
        return dummy->next;
    }
};