
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head,ListNode* end=NULL) {
        ListNode *fast,*slow;
        fast=slow=head;
        if(head==end) return NULL;
        while(fast!=end and fast->next!=end)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow==NULL) return NULL;
        TreeNode *tmp=new TreeNode(slow->val);
        tmp->left=sortedListToBST(head,slow);
        tmp->right=sortedListToBST(slow->next,end);
        return tmp;
    }
};