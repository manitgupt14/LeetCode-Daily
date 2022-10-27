//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Trie{
    public:
    Trie* child[26];
    bool isEnd;
    int ct=0;
    Trie(){
        for(int i=0;i<26;i++)
        child[i]=NULL;
        this->isEnd=false;
        this->ct=0;
    }
};
class Solution
{
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
            {
                tmp->child[s[i]-'a']=new Trie();
            }
            tmp=tmp->child[s[i]-'a'];
            tmp->ct+=1;
        }
        tmp->isEnd=true;
        return ;
    }
    string search(string s)
    {
      Trie* tmp=root;
      string res="";
      for(int i=0;i<s.size();i++)
      {
          res+=s[i];
          if(tmp->child[s[i]-'a']->ct==1)
          return res;
          tmp=tmp->child[s[i]-'a'];
      }
      return res;
    }
    vector<string> findPrefixes(string arr[], int n)
    {
      for(int i=0;i<n;i++)
      insert(arr[i]);
      
      vector<string> ans;
      for(int i=0;i<n;i++)
      {
          ans.push_back(search(arr[i]));
      }
      return ans;
      
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends