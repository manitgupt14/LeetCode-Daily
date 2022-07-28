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
class FindElements {
public:
    TreeNode *newroot=NULL;
    unordered_set<int> tmp;
    void maketree(TreeNode* root)
        {
         int k=root->val;
          
        if(root->left!=NULL)
            {
             root->left->val=2*k+1;
            tmp.insert(2*k+1);
            maketree(root->left);
            }
         
        if(root->right!=NULL)
            {
             root->right->val=2*k+2;
            tmp.insert(2*k+2);
            maketree(root->right);
            }
        return ;
        }
    FindElements(TreeNode* root) {
        newroot=root;
        newroot->val=0;
        maketree(newroot);
    }
    
    bool find(int target) {
        return tmp.find(target)!=tmp.end() or target==0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */