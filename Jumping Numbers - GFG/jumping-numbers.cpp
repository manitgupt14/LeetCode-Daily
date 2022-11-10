//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    unordered_set<long long int> us;
    void isdn(long long int i,long long int n,long long int m)
    {
        if(i>=1e11)
        return ;
        else if(i>=n and i<=m)
        {us.insert(i);}
        
        int vl=i%10;
        
        if(vl+1<=9)
        isdn(i*10+vl+1,n,m);
        
        if(vl-1>=0)
        isdn(i*10+vl-1,n,m);
        
        return ;
    }
  public:
    long long jumpingNums(long long X) {
        vector<long long> ans;
       us.clear();
       for(int i=0;i<=9;i++)
       {
          isdn(i,0,X);
       }
       for(auto it:us)
       ans.push_back(it);
       sort(ans.begin(),ans.end());
       
       long long int low=0,high=ans.size()-1;
       long long ct=0;
       while(low<=high)
       {
           long long int mid=(low+high)/2;
           if(ans[mid]<=X)
           {
               ct=ans[mid];
               low=mid+1;
           }
           else
           high=mid-1;
       }
       return ct;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends