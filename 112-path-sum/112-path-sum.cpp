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
    bool hasPathSum(TreeNode* root, int targetSum,int sum=0) {
        if(root==NULL)
        {
            return false;
        }
        
        if(root->left==NULL and root->right==NULL and targetSum-root->val==sum)
            return true;
        
        return hasPathSum(root->left,targetSum,sum+root->val) || hasPathSum(root->right,targetSum,sum+=root->val);
    }
};