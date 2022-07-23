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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode *first,*second,*prev;
        first=second=head;
        prev=NULL;
        while(second!=NULL)
        {
            while(first!=NULL and first->val<x)
            {
                first=first->next;
            }
            second=first;
            while(second!=NULL and second->val>=x)
            {
                prev=second;
                second=second->next;
            }
            
            if(first!=NULL and second!=NULL)
            {
                swap(first->val,second->val);
                prev->next=second->next;
                second->next=first->next;
                first->next=second;
            }
            if(first!=NULL and prev!=NULL)
            {first=first->next;
            second=prev->next;}
        }
        return head;
    }
};