class Solution {
public:
    int dfs(vector<int> &mr,vector<int> &it,vector<int> adj[],int ans,int par)
    {
        int res=0;
        for(auto i:adj[par])
        {
            int k=dfs(mr,it,adj,ans,i)+it[par];
            res=max(res,k);
        }
        
        return res+ans;
    }
    int numOfMinutes(int n, int hD, vector<int>& mr, vector<int>& it) {
        vector<int> adj[n];
        int ans=0;
        for(int i=0;i<mr.size();i++)
        {
            if(mr[i]!=-1)
            {
               adj[mr[i]].push_back(i); 
            }
        }
        ans+=dfs(mr,it,adj,0,hD);
        
        return ans;
    }
};