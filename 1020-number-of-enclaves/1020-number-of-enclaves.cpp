class Solution {
private:
   bool dfs(vector<vector<int>> &v,int i,int j,int &ct)
   {
   
    if(i<0 || j<0 || i>=v.size() || j>=v[0].size())
        return false;
    
     if(v[i][j]==0 or v[i][j]==2)
         return true;
    
    v[i][j]=2;
    ct++;
    bool a=dfs(v,i+1,j,ct);
    bool b=dfs(v,i-1,j,ct);
    bool c=dfs(v,i,j+1,ct);
    bool d=dfs(v,i,j-1,ct);
    if(a and b and c and d)
        return true;
    
    return false;
       
  }    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int c=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int ct=0;
                if(grid[i][j]==1)
                {
                    bool flag=dfs(grid,i,j,ct);
                    if(flag) 
                    c+=ct; 
                }
            }
        }
        return c;
    }
};