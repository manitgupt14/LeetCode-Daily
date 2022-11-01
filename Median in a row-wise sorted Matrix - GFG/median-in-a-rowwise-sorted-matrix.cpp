//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int low=0,high=2000;
        while(low<=high)
        {
            int m=(low+high)/2;
            int count=0;
            for(int i=0;i<r;i++)
            {
                int l=0,h=c-1;
                while(l<=h)
                {
                    int mid=l+(h-l)/2;
                    if(matrix[i][mid]<=m) l=mid+1;
                    else h=mid-1;
                }
                count+=l;
            }
            if(count<=(r*c)/2) low=m+1;
            else high=m-1;
        }
        return low;
    }
    
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends