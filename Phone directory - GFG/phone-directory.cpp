//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Trie
{
    public:
    Trie *child[26];
    bool isEnd=false;
    Trie()
    {
       for(int i=0;i<26;i++)
       {
          this->child[i]=NULL;
       }
       this->isEnd=false;
    }
};
class Solution{
  private:
  Trie *root;
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
       }
       tmp->isEnd=true;
  }
  void findstring(Trie* tmp,string tt,vector<string> &tmpq)
  {
      if(tmp->isEnd)
      {
          tmpq.push_back(tt);
      }
      for(int i=0;i<26;i++)
      {
          if(tmp->child[i]!=NULL)
          {
              tt.push_back( i+'a' );
              findstring(tmp->child[i],tt,tmpq);
              tt.pop_back();
          }
      }
      return ;
  }
public:
    Solution()
    {
        root=new Trie();
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        for(int i=0;i<n;i++)
        {
            insert(contact[i]);
        }
        
        Trie* tmp=root;
        vector<vector<string>> ans;
        string tt="";
        bool flag=true;
        for(int i=0;i<s.size();i++)
        {
            
            if(tmp->child[s[i]-'a']!=NULL and flag)
            {
                vector<string> tmpq;
                tt+=s[i];
                tmp=tmp->child[s[i]-'a'];
                findstring(tmp,tt,tmpq);
                ans.push_back(tmpq);
            }
            else
            {
                flag=false;
                ans.push_back({"0"});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends