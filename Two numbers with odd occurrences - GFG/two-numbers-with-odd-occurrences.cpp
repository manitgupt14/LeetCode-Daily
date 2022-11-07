//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
    long long int val=0;
    for(int i=0;i<n;i++)
    {
        val^=arr[i];
    }
    long long int vl=0;
    for(int i=0;i<64;i++)
    {
        if( val & (1<<i))
        {
            vl=(1<<i);
            break;
        }
    }
    long long int tm1=0;
    long long int tm2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] & vl)
        {
            tm1^=arr[i];
        }
        else
        {
            tm2^=arr[i];
        }
    }
    
    
    long long int first=tm2;
    long long int sec=tm2;
    for(int i=0;i<n;i++)
    {
        if((arr[i]^tm1)==0)
        {
            sec=arr[i];
            break;
        }
    }
    if(sec==tm2)
    {
        first=tm1;
    }
    vector<long long int> ans;
    ans.push_back(first);
    ans.push_back(sec);
    if(ans[0]<ans[1])
    swap(ans[0],ans[1]);
    
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
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends