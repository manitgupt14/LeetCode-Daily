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
    private:
    int solve(TreeNode* root)
    {
        if(!root) return 0;
        
        int lheight=solve(root->left);
        int rheight=solve(root->right);
        
        if(lheight<0 or rheight<0) return -1;
        
        if(abs(lheight-rheight)>1) return -1;
        
        return 1+max(lheight,rheight);
    }
public:
    bool isBalanced(TreeNode* root) {
       if(solve(root)<0) return false;
        return true;
    }
};