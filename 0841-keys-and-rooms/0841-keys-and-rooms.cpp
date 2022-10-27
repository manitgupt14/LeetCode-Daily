class Solution {
public:
    void dfs(vector<vector<int>> &rooms,vector<int> &visi,int i)
    {
        visi[i]=1;
        
        for(int j=0;j<rooms[i].size();j++)
        {
            if(visi[rooms[i][j]]==0)
                dfs(rooms,visi,rooms[i][j]);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> visi(n,0);
        visi[0]=0;
        
        dfs(rooms,visi,0);
        
        for(int i=0;i<n;i++)
            if(visi[i]==0)
                return false;
        return true;
    }
};