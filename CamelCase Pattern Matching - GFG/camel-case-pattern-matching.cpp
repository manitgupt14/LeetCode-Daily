//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> queries, string pattern) {
        vector<string> ans;
        for(int i=0;i<N;i++)
        {
            int k=0,d=0;
            int n=queries[i].size(),size=pattern.size();
            while(k<n)
            {
                if(d<size and pattern[d]==queries[i][k])
                    d++;
                else if(queries[i][k]>='A' and queries[i][k]<='Z')
                {
                    break;
                }
                k++;
            }
            if(d==size) ans.push_back(queries[i]);
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
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends