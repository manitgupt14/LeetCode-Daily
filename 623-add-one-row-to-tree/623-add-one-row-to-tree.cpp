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
    TreeNode* addOneRow(TreeNode* root, int val, int depth,bool isleft=true) {
        if(depth==1)
        {
            if(root==NULL)
                return new TreeNode(val);
            else if(isleft)
                return new TreeNode(val,root,NULL);
            else
                return new TreeNode(val,NULL,root);
        }
        if(!root) return NULL;
        root->left=addOneRow(root->left,val,depth-1,true);
        root->right=addOneRow(root->right,val,depth-1,false);
        
        return root;
    }
};