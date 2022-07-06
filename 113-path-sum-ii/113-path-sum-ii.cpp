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
    void findsum(TreeNode* root,int targetSum,vector<vector<int>> &ans,vector<int> &tmp,int currsum)
    {
        if(root==NULL)
            return ;
        
        tmp.push_back(root->val);
        currsum+=root->val;
        
        if(root->left==NULL and root->right==NULL)
        {
            if(targetSum==currsum)
            {
                ans.push_back(tmp);
                tmp.pop_back();
                return ;
            }
            else
            {
                tmp.pop_back();
                return ;
            }
        }
        
        findsum(root->left,targetSum,ans,tmp,currsum);
        findsum(root->right,targetSum,ans,tmp,currsum);
        
        tmp.pop_back();
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> ans;
        vector<int> tmp;
        findsum(root,targetSum,ans,tmp,0);
        return ans;
    }
};