//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> matrix)
	{
	  vector<int> ans;
       for(int i=0;i<matrix[0].size();i++)
       {
           int r=0,c=i;
           int k=ans.size();
           while(r<matrix.size() and c>=0)
           {
               ans.push_back(matrix[r][c]);
               c--;
               r++;
           }
       }
       for(int i=1;i<matrix.size();i++)
       {
           int r=i,c=matrix[0].size()-1;
           int k=ans.size();
           while(r<matrix.size() and c>=0)
           {
               ans.push_back(matrix[r][c]);
               c--;
               r++;
           }
       }
       return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends