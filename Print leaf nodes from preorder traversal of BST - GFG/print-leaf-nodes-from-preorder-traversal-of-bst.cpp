//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Node{
  public:
  int data;
  Node *left,*right;
  Node()
  {
      
  }
  Node(int data)
  {
      this->data=data;
      this->left=NULL;
      this->right=NULL;
  }
  Node(int data,Node *left,Node *right)
  {
      this->data=data;
      this->left=left;
      this->right=right;
  }
};
class Solution {
  public:
    Node* insert(Node* root,int k)
    {
        if(!root)
        {
            return new Node(k);
        }
        if(root->data<k)
        {
            root->right=insert(root->right,k);
        }
        
        else if(root->data>k)
        {
            root->left=insert(root->left,k);
        }
        return root;
    }
    void inorder(Node *root,vector<int> &ans)
    {
        if(!root) return ;
        if(!root->left and !root->right)
        {
            ans.push_back(root->data);
            return ;
        }
        inorder(root->left,ans);
        inorder(root->right,ans);
    }
    vector<int> leafNodes(int arr[],int N) {
        Node* root=new Node(arr[0]);
        for(int i=1;i<N;i++)
        {
            root=insert(root,arr[i]);
        }
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends