//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        int nr=0,ng=0,nb=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='R')
            nr++;
            else if(a[i]=='G')
            ng++;
            else if(a[i]=='B')
            nb++;
        }
        if(!nr and !ng)
        return nb;
        else if(!nb and !ng)
        return nr;
        else if(!nr and !nb)
        return ng;
        
        else if( ((nr&1) and (ng&1) and (nb&1)) or (!(nr&1) and !(ng&1) and !(nb&1)) )
        return 2;
        return 1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends