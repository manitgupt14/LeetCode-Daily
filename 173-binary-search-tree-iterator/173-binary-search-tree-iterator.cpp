class BSTIterator {
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode* root) {
         TreeNode* qw=root;
        while(qw!=NULL)
        {
            st.push(qw);
            qw=qw->left;
        }
    }
    int next(){
     TreeNode* ans=st.top();
        st.pop();
        int vww=ans->val;
        if(ans->right!=NULL)
        {
            ans=ans->right;
            while(ans!=NULL)
            {
                st.push(ans);
                ans=ans->left;
            }
        }
        return vww;
    }
    bool hasNext(){
       return (!st.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */