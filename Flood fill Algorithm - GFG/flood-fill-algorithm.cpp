//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void dfs(vector<vector<int>> &image,int i,int j,int oldvl)
{
    if(i>=image.size() or j>=image[0].size() or i<0 or j<0 or image[i][j]!=oldvl)
    {
        return ;
    }
    image[i][j]=-1;
    dfs(image,i+1,j,oldvl);
    dfs(image,i-1,j,oldvl);
    dfs(image,i,j+1,oldvl);
    dfs(image,i,j-1,oldvl);
    return ;
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int n=image.size();
    int m=image[0].size();
    dfs(image,sr,sc,image[sr][sc]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(image[i][j]==-1)
                image[i][j]=newColor;
        }
    }
   return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends