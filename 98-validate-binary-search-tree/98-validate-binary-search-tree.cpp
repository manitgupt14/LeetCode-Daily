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
bool check(TreeNode* root,long p,long q) // CURRENT ELEMENT MUST BE IN RANGE B/W P AN Q
{
    if(root==NULL)
        return true; //  NO ONE RETURN TRUE
    int v=root->val; // CURRENT VALUE
    // if(root->left!=NULL && root->left->val>root->val )
    //         return false;   // LEFT ROOT SATISFIED
    // if(root->right!=NULL && root->right->val<root->val)
    //         return false;
    return (root->val>p && root->val<q && check(root->left,p,v) && check(root->right,v,q)); 
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        int p=1<<31; // INT_MIN CALCULATED
        long d=p; // FOR OVERFLOW
        return check(root,d-1,-1*(d));
    }
};