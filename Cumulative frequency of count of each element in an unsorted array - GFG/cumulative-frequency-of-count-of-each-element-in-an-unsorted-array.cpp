//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    vector<int> countFreq(int a[], int n) 
    { 
        sort(a,a+n);
        
        vector<int> ans;
        int ct=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
            {
                ans.push_back(ct);
            }
            ct++;
        }
        ans.push_back(ct);
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
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    vector<int> v;
	    v = ob.countFreq(arr, n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout<<'\n';
	}
	return 0;
}
// } Driver Code Ends