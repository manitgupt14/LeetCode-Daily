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
TreeNode* root;
TreeNode* form(vector<int>& pr,vector<int>& in,int st,int en,int &k)
{
    if(st>en)
        return NULL;
    int i;
    for(i=st;i<=en;i++)
    {
        if(in[i]==pr[k])
        {
            break;
        }
    }
    k++;
    TreeNode* root=new TreeNode(in[i]);
    root->left=form(pr,in,st,i-1,k);
    root->right=form(pr,in,i+1,en,k);
    return root;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        int w=0;
        int n=p.size();
        return form(p,i,w,n-1,w);
    }
};