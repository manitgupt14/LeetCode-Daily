//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int V=matrix.size();
	    int dist[V][V], i, j, k;
	    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
        {    dist[i][j] = matrix[i][j];
             if(dist[i][j]==-1)
             {
                 dist[i][j]=99999;
             }
        }   
        for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != 99999
                        && dist[i][k] != 99999))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
        }
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(dist[i][j]==99999)
                {
                    matrix[i][j]=-1;
                }
                else
                matrix[i][j]=dist[i][j];
            }
        }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends