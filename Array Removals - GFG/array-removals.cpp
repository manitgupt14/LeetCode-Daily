//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        sort(arr.begin(),arr.end());
        int i=0,j=0;
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            while(arr[i]-arr[j]>k)
            {
                j++;
            }
            ans=max(ans,i-j+1);
        }
        
        return arr.size()-ans;
    }
};
//1 3 4 9 10 11 12 17 20


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends