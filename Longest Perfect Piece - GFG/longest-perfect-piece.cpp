//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int n) {
        map<int,int> mp;
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            while(mp.rbegin()->first - mp.begin()->first > 1)
            {
                mp[arr[j]]--;
                if(mp[arr[j]]==0)
                mp.erase(arr[j]);
                j++;
            }
            ans=max(ans,i-j+1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends