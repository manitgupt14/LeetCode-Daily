/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int findheight(TreeNode root)
    {
        if(root==null)
            return 0;
        return Math.max(findheight(root.left),findheight(root.right))+1;
    }
    public void fillrightview(TreeNode root,List<Integer> temp,int level)
    {
        if(root==null) return ;
        
        temp.set(level,root.val);
        
        fillrightview(root.left,temp,level+1);
        fillrightview(root.right,temp,level+1);
        
    }
    public List<Integer> rightSideView(TreeNode root) {
        int height=findheight(root);
        if(height==0) return new ArrayList<Integer>();
        List<Integer> st=new ArrayList();
        
        for(int i=0;i<height;i++)
            st.add(-1);
        
        fillrightview(root,st,0);
        
        return st;
    }
}