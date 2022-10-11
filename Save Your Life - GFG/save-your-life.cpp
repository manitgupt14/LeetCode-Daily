//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          int vl=0;
          unordered_map<char,int> mp;
          for(int i=0;i<n;i++)
          {
              mp[x[i]]=b[i];
          }
          for(char ch='a';ch<='z';ch++)
          {
               if(mp.find(ch)==mp.end())
               {
                   mp[ch]=ch;
               }
          } 
          for(char ch='A';ch<='Z';ch++)
          {
               if(mp.find(ch)==mp.end())
               {
                   mp[ch]=ch;
               }
          } 
          
         
          string ans="";
          int mx=0;
          int tmp=0;
          int stra=0,end=0,s=0;
          for(int i=0;i<w.size();i++)
          {
              tmp+=mp[w[i]];
              if(mx<tmp)
              {
                  mx=tmp;
                  stra=s;
                  end=i;
              }
              if(tmp<0)
              {
                  tmp=0;
                  s=i+1;
              }
          }
          
          return w.substr(stra,end-stra+1);
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends