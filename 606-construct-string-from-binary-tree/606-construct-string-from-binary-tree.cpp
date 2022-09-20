class Solution {
public:
    string tree2str(TreeNode* root,string ans="") {
        if((!root)) return ans;
        
        ans+=to_string(root->val);
        if(root->left!=NULL)
        {
            ans+="(";
            ans=tree2str(root->left,ans);
            ans+=")";
        }
        if(root->left==NULL and root->right!=NULL)
        {
        ans+="()";
        }        
        if(root->right!=NULL)
        {
            ans+="(";
            ans=tree2str(root->right,ans);
            ans+=")";
        }
        return ans;
    }
};