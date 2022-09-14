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
    void solve(TreeNode* root,unordered_map<int,int> &mp,int &ans)
    {
        if((!root))
        {
            return ;
        }
        mp[root->val]++;
        
        if((!root->left) and (!root->right))
        {
            int ct_o=0;
            for(auto it:mp)
            {
                if(it.second%2!=0)
                    ct_o++;
            }
            if(ct_o<=1)
                ans++;
            mp[root->val]--;
            return ;
        }
        
        solve(root->left,mp,ans);
        solve(root->right,mp,ans);
        mp[root->val]--;
        return ;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        int ans=0;
        solve(root,mp,ans);
        return ans;
    }
};