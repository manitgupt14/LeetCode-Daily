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
ListNode* reverse(ListNode* head)
{
    if(head==NULL)
            return head;
        ListNode *curr,*pre,*ne;
        pre=NULL;
        curr=head;
        ne=curr->next;
        while(curr->next!=NULL)
        {
            curr->next=pre;
            pre=curr;
            curr=ne;
            ne=ne->next;
        }
        curr->next=pre;
        return curr;
}
class Solution {
public:
    void reorderList(ListNode* head) {
        int len=0;
        ListNode* z=head;
        while(z!=NULL)
        {
            len++;
            z=z->next;
        }
        if(len<3)
            return ;
        z=head;
        int i=0;
        ListNode* s;
        while(i<len/2-1)
        {
            i++;
            z=z->next;
        }
        s=z->next;
        z->next=NULL;
        z=head;
        s=reverse(s);
        ListNode* d;
        while(z!=NULL && s!=NULL)
        {
            ListNode* r=new ListNode(s->val,z->next);
            z->next=r;
            if(r->next==NULL)
                d=r;
            z=r->next;
            s=s->next;
        }
        if(s!=NULL)
        {
            ListNode* r=new ListNode(s->val,s->next);
            d->next=r;
        }
        return ;
    }
};