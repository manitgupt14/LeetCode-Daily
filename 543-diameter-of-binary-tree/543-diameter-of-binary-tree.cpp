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
    int diameterOfBinaryTree(TreeNode* root)
    {
        int mx=0;
        dia(root,mx);
        return mx;
    }
    private:
    int dia(TreeNode* root,int &mx) {
       if(root==NULL)
           return 0;
       int lh=dia(root->left,mx);
       int rh=dia(root->right,mx);
        mx=max(mx,lh+rh);
       return 1+max(lh,rh);
    }
};