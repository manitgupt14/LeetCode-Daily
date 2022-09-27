/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode *> qw;
        qw.push(root);
        int l=0;
        while(!qw.empty())
        {
            qw.push(NULL);
            int vl;
            if(l%2==0) vl=-1;
            else vl=1e7;
            while(qw.front()!=NULL)
            {
                TreeNode *tp=qw.front();
                qw.pop();
                if(l%2==0 and (tp->val%2==0 or tp->val<=vl))
                    return false;
                 if(l%2!=0 and (tp->val%2!=0 or tp->val>=vl))
                    return false;
                vl=tp->val;
                if(tp->left) qw.push(tp->left);
                if(tp->right) qw.push(tp->right);
            }
            qw.pop();
            l++;
        }
        return true;
    }
};