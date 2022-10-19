//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    void dfs(vector<vector<char>> &mat,vector<vector<int>> &visi,string target,int i,int x,int y,int &ct)
    {
        if(x>=mat.size() or y>=mat[0].size() or x<0 or y<0 or visi[x][y]==1)
        return ;
        
        if(i==target.size()-1 and mat[x][y]==target[i])
        {
        ct++;
        return ;
        }
        
        if(mat[x][y]!=target[i])
        return ;
        
        visi[x][y]=1;
        
        dfs(mat,visi,target,i+1,x+1,y,ct);
        dfs(mat,visi,target,i+1,x,y-1,ct);
        dfs(mat,visi,target,i+1,x-1,y,ct);
        dfs(mat,visi,target,i+1,x,y+1,ct);
        
        
        visi[x][y]=0;
        return ;
    }
    public:
    int findOccurrence(vector<vector<char> > &mat, string target){
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> visi(n,vector<int> (m,0));
        
        int ct=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==target[0])
                {
                dfs(mat,visi,target,0,i,j,ct);
                }
            }
        }
        
        return ct;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends