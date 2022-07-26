/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool find(TreeNode *a,TreeNode *b)
{
    if(a==NULL || b==NULL)
        return false;
    if(a->val==b->val)
        return true;
    if(a->left!=NULL && find(a->left,b))
        return true;
    else if(a->right!=NULL && find(a->right,b))
        return true;
    return false;
}
TreeNode* finde(TreeNode* root,TreeNode* a,TreeNode* b)
{
    
    if(find(root->left,a) && find(root->right,b))
        return root;
    if(find(root->right,a) && find(root->left,b))
        return root;
    if(find(root->left,a) && find(root->left,b))
        return finde(root->left,a,b);
    if(find(root->right,a) && find(root->right,b))
        return finde(root->right,a,b);
    return root;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          if(find(p,q))
              return p;
        else if(find(q,p))
            return q;
        TreeNode* z=finde(root,p,q);
        return z;
    }
};