//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod=1e8;
    int fillingBucket(int N) {
      long long dp[N+1];
      if(N==1 or N==2)
      return N;
      dp[0]=1;
      dp[1]=1;
      for(int i=2;i<=N;i++)
      {
          dp[i]=dp[i-1]+dp[i-2];
          dp[i]%=mod;
      }
      return dp[N];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends