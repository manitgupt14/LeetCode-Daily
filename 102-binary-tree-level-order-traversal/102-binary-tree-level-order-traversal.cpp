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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
        return {};
        queue<TreeNode *> qw;
        vector<vector<int>> ans;
        qw.push(root);
        vector<int> tmp;
        while(!qw.empty())
        {
            qw.push(NULL);
            while(!qw.empty() and qw.front()!=NULL)
            {
                TreeNode *curr=qw.front();
                qw.pop();
                tmp.push_back(curr->val);
                if(curr->left!=NULL)
                    qw.push(curr->left);
                if(curr->right!=NULL)
                    qw.push(curr->right);
            }
            qw.pop();
            ans.push_back(tmp);
            tmp.clear();
        }
        
        return ans;
    }
};