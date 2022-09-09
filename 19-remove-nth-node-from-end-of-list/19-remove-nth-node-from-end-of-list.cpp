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
    ListNode* removeNthFromEnd(ListNode* head, int &K) {
    if(head==NULL)
    {
        return NULL;
    }
    head->next=removeNthFromEnd(head->next,K);
    K-=1;
    if(K==0)
    {
        if(head->next==NULL)
            return NULL;
        else
        {
            swap(head->val,head->next->val);
            head->next=head->next->next;
            return head;
        }
    }
    return head;
    }
};