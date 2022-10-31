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
    bool checkSame(TreeNode* root,TreeNode* subRoot)
    {
        if(!root or !subRoot) return root==subRoot;
        return (root->val==subRoot->val and checkSame(root->left,subRoot->left) and checkSame(root->right,subRoot->right));
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(root->val==subRoot->val and checkSame(root,subRoot))
            return true;
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};