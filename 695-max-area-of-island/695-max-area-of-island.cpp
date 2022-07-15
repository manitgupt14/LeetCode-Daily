class Solution {
public:
    void dfs(vector<vector<int>> &grid,int i,int j,int &ans,int &val)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]!=1)
        return ;
        val++;
        
        ans=max(val,ans);
        
        grid[i][j]=-1;
        
        dfs(grid,i+1,j,ans,val);
        dfs(grid,i-1,j,ans,val);
        dfs(grid,i,j+1,ans,val);
        dfs(grid,i,j-1,ans,val);
        
        return ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int ans=0;
        int val;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                val=0;
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j,ans,val);
                }
            }
        }
        
        
        return ans;
        
    }
};