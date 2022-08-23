class Solution {
public:
    void findsum(TreeNode* root,int targetSum,vector<vector<int>> &ans,vector<int> &tmp,int &currsum)
    {
        if(root==NULL)
            return ; 
        
        tmp.push_back(root->val);
        currsum+=root->val;
        
        if(root->left==NULL and root->right==NULL)
        {
            if(targetSum==currsum)
            ans.push_back(tmp);
            
            currsum-=tmp.back();
            tmp.pop_back();
                return ;
        }
        
        findsum(root->left,targetSum,ans,tmp,currsum); 
        findsum(root->right,targetSum,ans,tmp,currsum);
        
        currsum-=tmp.back();
        tmp.pop_back();
        
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> ans; 
        vector<int> tmp; 
        int currsum=0;
        findsum(root,targetSum,ans,tmp,currsum); 
        return ans;
    }
};