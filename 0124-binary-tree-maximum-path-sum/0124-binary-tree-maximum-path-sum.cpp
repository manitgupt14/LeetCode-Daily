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
    int mxpa(TreeNode* root,int &ans)
    {
        if(!root) return 0;
        int l=mxpa(root->left,ans);
        int r=mxpa(root->right,ans);
        int mxst=max(max(l,r)+root->val,root->val); // CASE 1
        int mxca=max(mxst,l+r+root->val); // Case 2 and 1  compared
        ans=max(mxca,ans);
        return mxst;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        mxpa(root,ans);
        return ans;
    }
};