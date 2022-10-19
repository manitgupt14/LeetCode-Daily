//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    bool dfs(vector<int> adj[],vector<int> &visi,int i,int n,int &ct)
    {
        if(visi[i]==1)
        return false;
        
        visi[i]=1;
        ct++;
        if(ct==n)
        return true;
        
        for(auto it:adj[i])
        {
            if(dfs(adj,visi,it,n,ct))
            return true;
        }
        ct--;
        visi[i]=0;
        return false;
    }
    public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<int> adj[N];
        for(int i=0;i<M;i++)
        {
            int a=Edges[i][0]-1;
            int b=Edges[i][1]-1;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int> visi(N,0);
        
        for(int i=0;i<N;i++)
        {
            int ct=0;
            bool flag=dfs(adj,visi,i,N,ct);
            if(flag)
            return true;
        }
        
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends