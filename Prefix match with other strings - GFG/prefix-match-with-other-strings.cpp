//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Trie{
  public:
  Trie* child[26];
  int ct=0;
  bool isEnd=false;
  Trie()
  {
    for(int i=0;i<26;i++)
    this->child[i]=NULL;
    isEnd=false;
    ct=0;
  }
};
class Solution{   
public:
    Trie *root;
    Solution()
    {
        root=new Trie();
    }
    void insert(string s)
    {
        Trie* tmp=root;
        for(int i=0;i<s.size();i++)
        {
            if(tmp->child[s[i]-'a']==NULL)
            tmp->child[s[i]-'a']=new Trie();
            tmp=tmp->child[s[i]-'a'];
            tmp->ct+=1;
        }
        tmp->isEnd=true;
    }
    int solve(string s)
    {
        Trie* tmp=root;
        for(int i=0;i<s.size();i++)
        {
            if(tmp->child[s[i]-'a']==NULL)
            return 0;
            tmp=tmp->child[s[i]-'a'];
        }
        return tmp->ct;
    }
    int klengthpref(string arr[], int n, int k, string str){    
        for(int i=0;i<n;i++)
        {
            insert(arr[i]);
        }
        string temp=str.substr(0,k);
        return solve(temp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends