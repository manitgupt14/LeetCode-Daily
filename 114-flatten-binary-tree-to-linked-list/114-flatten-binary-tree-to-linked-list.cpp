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
void preorder(TreeNode *root,vector<int> &ans)
{
    if(root==NULL)
        return ;
    ans.push_back(root->val);
    preorder(root->left,ans);
    preorder(root->right,ans);
}
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return ;
        vector<int> ans;
        preorder(root,ans);
        
        root->val=ans[0];
        TreeNode *ow=root;
        int i=1;
        while(i<ans.size())
        {
            if(ow->right!=NULL)
            ow->right->val=ans[i];
            else
                ow->right=new TreeNode(ans[i]);
            ow->left=NULL;
            ow=ow->right;
            i++;
        }
    }
};