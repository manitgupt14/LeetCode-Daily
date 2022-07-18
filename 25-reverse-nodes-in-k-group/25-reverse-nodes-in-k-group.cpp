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
    vector<ListNode *>  reverse(ListNode* st_prev,ListNode* start,ListNode* end)
    {
        ListNode* current = start;
        ListNode *prev = end, *next = NULL;
 
        while (current != end) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return {prev,current,start};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
            return head;
        ListNode *prev=NULL,*start=head,*end;
        ListNode *temp=head;
        int i=0;
        while(temp!=NULL)
        {
            i++;
            if(i==k)
            {
                end=temp;
                vector<ListNode *> ans=reverse(prev,start,end->next);
                if(prev!=NULL)
                    prev->next=ans[0];
                else
                    head=ans[0];
                start=ans[1];
                prev=ans[2];
                temp=ans[1];
                i=0;
            }
            else
            temp=temp->next;
        }
        return head;
    }
};