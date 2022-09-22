/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode *,TreeNode *> mp;
    unordered_set<TreeNode *> us;
    void findpar(TreeNode *root,TreeNode *par)
    {
        if(!root) return ;
        mp[root]=par;
        findpar(root->left,root);
        findpar(root->right,root);
        return ;
    }
    void findans(TreeNode *root,int di,vector<int> &ans,int k)
    {
        if(!root or us.find(root)!=us.end())
        return ;
        
        if(di==k)
        {
            ans.push_back(root->val);
            return ;
        }
        us.insert(root);
        
        findans(mp[root],di+1,ans,k);
        findans(root->left,di+1,ans,k);
        findans(root->right,di+1,ans,k);
        return ;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         vector<int> ans;
        
        findpar(root,NULL);
        findans(target,0,ans,k);
        return ans;
    }
};