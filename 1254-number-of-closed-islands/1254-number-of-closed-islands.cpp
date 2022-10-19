class Solution {
    private:
    bool dfs(vector<vector<int>> &v,int i,int j)
   {
   
    if(i<0 || j<0 || i>=v.size() || j>=v[0].size())
        return false;
    
     if(v[i][j]==1 or v[i][j]==2)
         return true;
    
    v[i][j]=2;    
    bool a=dfs(v,i+1,j);
    bool b=dfs(v,i-1,j);
    bool c=dfs(v,i,j+1);
    bool d=dfs(v,i,j-1);
    if(a and b and c and d)
        return true;
    
    return false;
       
  }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int c=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                {
                    bool flag=dfs(grid,i,j);
                    if(flag) 
                    {c++;  } 
                }
            }
        }
        return c;
    }
};