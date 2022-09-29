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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,int carry=0) {
        if(!(l1) and !l2 and carry==0) return NULL;
        
        if((!l1)) l1=new ListNode(0);
        if(!l2) l2=new ListNode(0);
        
        l1->val+=l2->val+carry;
        
        carry=l1->val/10;
        l1->val=l1->val%10;
        
        l1->next=addTwoNumbers(l1->next,l2->next,carry);
        
        return l1;
    }
};