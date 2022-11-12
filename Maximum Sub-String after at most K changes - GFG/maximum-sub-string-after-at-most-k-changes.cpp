//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    int start=0,mx=0,ans=0;
           int arr[26]={0};
           for(int i=0;i<s.length();i++){
            arr[s[i]-'A']+=1;
            mx=max(mx,arr[s[i]-'A']);
            if(abs(mx-(i-start+1))>k){
                arr[s[start]-'A']-=1;
                mx=0;
                start++;
                for(int ele:arr) mx=max(ele,mx);
            }
            ans=max(ans,i-start+1);
            }
           return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends