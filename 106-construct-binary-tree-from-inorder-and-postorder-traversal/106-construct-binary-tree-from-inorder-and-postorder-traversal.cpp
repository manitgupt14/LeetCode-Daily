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
     TreeNode* insert(TreeNode *root,int vl,unordered_map<int,int> &mp)
    {
    if(!root) return new TreeNode(vl);
    if(mp[root->val]<mp[vl])
    {
        root->right=insert(root->right,vl,mp);
    }
    else if(mp[root->val]>mp[vl])
    {
        root->left=insert(root->left,vl,mp);
    }
    return root;
   }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
       int n=in.size(); 
       unordered_map<int,int> mp;
       for(int i=0;i<n;i++)
       {
           mp[in[i]]=i;
       }
       TreeNode *root=NULL;
       for(int i=n-1;i>=0;i--)
       {
            root=insert(root,post[i],mp);
       }
       return root;
    }
};