//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
          vector<int> r,c;
          for(auto it:enemy)
          {
              r.push_back(it[0]);
              c.push_back(it[1]);
              
          }
          
          r.push_back(0);
          c.push_back(0);
          r.push_back(n+1);
          c.push_back(m+1);
          sort(r.begin(),r.end());
          sort(c.begin(),c.end());
          int mxr=0,mxc=0;
          for(int i=1;i<r.size();i++)
          {
             mxr=max(mxr,r[i]-r[i-1]-1);
          }
          for(int i=1;i<c.size();i++)
          {
             mxc=max(mxc,c[i]-c[i-1]-1);
          }
          return mxr*mxc;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends