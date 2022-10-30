//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	   long long int dp[n+1];
	   dp[0]=0;
	   dp[1]=1;
	   long long int prev=1;
	   for(int i=2;i<=n and i<=6;i++)
	   {
	       dp[i]=prev*2;
	       prev+=dp[i];
	   }
	   for(int i=7;i<=n;i++)
	   {
	       dp[i]=(prev-dp[i-6])*2;
	       prev-=dp[i-6];
	       prev+=dp[i];
	   }
	   return prev;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends