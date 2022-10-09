class Solution {
public:
    unordered_map<TreeNode*,TreeNode *> mp;
    TreeNode* succesor(TreeNode* root)
    {
        if(root->right)
        {
            root=root->right;
            while(root->left)
                root=root->left;
            return root;
        }
        
        while(mp[root]!=NULL and mp[root]->right==root)
        {
            root=mp[root];
        }
        if(mp[root]==NULL)
            return NULL;
        else
        {
            return mp[root];
        }
    }
    TreeNode* predecess(TreeNode* root)
    {
        if(root->left)
        {
            root=root->left;
            while(root->right)
                root=root->right;
            return root;
        }
        
        while(mp[root]!=NULL and mp[root]->left==root)
        {
            root=mp[root];
        }
        if(mp[root]==NULL)
            return NULL;
        else
        {
            return mp[root];
        }
        
    }
    void findpar(TreeNode* root,TreeNode* par)
    {
        if(!root) return ;
        mp[root]=par;
        findpar(root->left,root);
        findpar(root->right,root);
        return ;
    }
    bool findTarget(TreeNode* root, int k) {
        findpar(root,NULL);
        TreeNode* a=root;
        TreeNode* b=root;
        while(a->left)
        {
            a=a->left;
        }
        while(b->right)
        {
            b=b->right;
        }
        
        while(a and b and a!=b)
        {
            if(a->val+b->val==k)
                 return true;
            else if(a->val+b->val>k)
                b=predecess(b);
            else 
                a=succesor(a);
        }
        return false;
    }
};