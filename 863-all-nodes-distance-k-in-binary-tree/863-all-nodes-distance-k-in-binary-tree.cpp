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
    void findpar(unordered_map<TreeNode *,TreeNode *> &mp,TreeNode *par,TreeNode *root)
    {
         if(root==NULL) return ;
        
        mp[root]=par;
        
        findpar(mp,root,root->left);
        findpar(mp,root,root->right);
        
        return ;
    }
    void findarr(TreeNode *root,vector<int> &ans,unordered_map<TreeNode *,TreeNode *> &mp,int dis,int k,TreeNode* target,unordered_set<TreeNode *> &visi)
    {
        if(root==NULL) return ;
        
        if(visi.find(root)!=visi.end())
            return ;
        
        if(dis==k)
        {
            ans.push_back(root->val);
            return ;
        }
        else if(dis==k)
            return ;
        
        visi.insert(root); 
        findarr(root->left,ans,mp,dis+1,k,target,visi);
        findarr(root->right,ans,mp,dis+1,k,target,visi);
        findarr(mp[root],ans,mp,dis+1,k,target,visi);
        
        return ;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode *,TreeNode *> mp;
        findpar(mp,NULL,root);
        unordered_set<TreeNode *> visi;
        findarr(target,ans,mp,0,k,target,visi);
        return ans;
    }
};