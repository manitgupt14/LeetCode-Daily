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
    vector<ListNode*>  reverse(ListNode* st_prev,ListNode* start,ListNode* end)
    {
        ListNode* current = start;
        ListNode *prev = end, *next = NULL;
 
        while (current != end) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return {prev,start};
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
            return head;
        ListNode *prev=NULL,*temp=head;
        int i=0;
        ListNode *start,*end;
        while(temp!=NULL)
        {
            i++;
            if(i<left)
                prev=temp;                
            if(i==left)
            start=temp;
            if(i==right)
            { end=temp;
               break;}
            temp=temp->next;
        }
        
        vector<ListNode *> ans=reverse(prev,start,end->next);
        
        if(prev!=NULL)
        prev->next=ans[0];
        else
            head=ans[0];
        return head;
    }
};