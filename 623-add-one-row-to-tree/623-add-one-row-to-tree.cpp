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
    TreeNode* add(TreeNode* root,int val,int depth,bool isleft)
    {
        if(depth==0)
        {
            if(root==NULL)
                return new TreeNode(val);
            else if(isleft)
                return new TreeNode(val,root,NULL);
            else
                return new TreeNode(val,NULL,root);
        }
        if(!root) return NULL;
        root->left=add(root->left,val,depth-1,true);
        root->right=add(root->right,val,depth-1,false);
        
        return root;
       
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        root=add(root,val,depth-1,true);
        return root;
    }
};