class Solution {
public:
    bool ans = true;
    long prev = LONG_MIN;
    bool isValidBST(TreeNode* root)
    {
        if(!root) return true ;   
        isValidBST(root->left);
        
         if(prev >= root->val)
         { return ans=false; }
         prev = root->val ;
        
        isValidBST(root->right);
        return ans ; 
    }
};