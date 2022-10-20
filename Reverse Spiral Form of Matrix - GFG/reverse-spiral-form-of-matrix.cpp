//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
       int top=0,down=a[0].size()-1,left=a.size()-1,right=0;
        int k=0;
        int n=a.size();
        int m=a[0].size();
        vector<int> ans;
        int i=0;
        while(i< n*m)
        {
            for(int j=k;j<a[0].size()-k && i< n*m;j++,i++)
                ans.push_back(a[right][j]);
            right++;
            //if(left!=right)
            for(int j=right;j<a.size()-k && i< n*m;j++,i++)
                ans.push_back(a[j][down]);
            down--;
            for(int j=down;j>=k && i< n*m;j--,i++)
                ans.push_back(a[left][j]);
            left--;
            for(int j=left;j>=right && i< n*m;j--,i++)
                ans.push_back(a[j][top]);
            top++;
            k++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends