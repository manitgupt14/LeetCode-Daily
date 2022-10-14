//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends

int dp[10005];
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        int mx=a[0];
        for(int i=0;i<n;i++)
        {
            mx=max(a[i],mx);
        }
        for(int i=0;i<=mx;i++)
        dp[i]=0;
        
        for(int i=0;i<n;i++)
        dp[ a[i] ]++;
        
        int mxsm=0;
        
        for(int i=mx;i>0;i--)
        {
            if(dp[i]>0)
            {
                mxsm+=(dp[i]*i);
                dp[i-1]-=dp[i];
            }
        }
        return mxsm;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends