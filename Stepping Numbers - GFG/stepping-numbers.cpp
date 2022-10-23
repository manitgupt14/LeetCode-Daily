//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    private:
    unordered_set<int> us;
    void isdn(int i,int n,int m)
    {
        if(i>=1e8)
        return ;
        else if(i>=n and i<=m)
        {us.insert(i);}
        
        int vl=i%10;
        
        if(vl+1<=9)
        isdn(i*10+vl+1,n,m);
        
        if(vl-1>=0)
        isdn(i*10+vl-1,n,m);
        
        return ;
    }
public:
    int steppingNumbers(int n, int m)
    {
        us.clear();
       int ct=0;
       for(int i=0;i<=9;i++)
       {
          isdn(i,n,m);
       }
      
       ct=us.size();
       return ct;
       
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends