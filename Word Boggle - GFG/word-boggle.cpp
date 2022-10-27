//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool dfs(vector<vector<char>> &boa,vector<vector<int>> &visi,int i,int j,string word,int ide)
    {
        if(i>=boa.size() or j>=boa[0].size() or visi[i][j]==1 or word[ide]!=boa[i][j])
        return false;
        
        if(ide==word.size()-1)
        {
            return true;
        }
        visi[i][j]=1;
        
        if( dfs(boa,visi,i,j-1,word,ide+1) or 
        dfs(boa,visi,i,j+1,word,ide+1) or
        dfs(boa,visi,i-1,j-1,word,ide+1) or
        dfs(boa,visi,i-1,j,word,ide+1) or
        dfs(boa,visi,i-1,j+1,word,ide+1) or
        dfs(boa,visi,i+1,j-1,word,ide+1) or
        dfs(boa,visi,i+1,j,word,ide+1) or
        dfs(boa,visi,i+1,j+1,word,ide+1)
        )
        
        {
            visi[i][j]=0;
            return true;
            
        }
        
        visi[i][j]=0;
        return false;
        
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	   int n=board.size();
	   int m=board[0].size();
	   vector<vector<int>> visi(n,vector<int> (m,0));
	   vector<string> ans;
	   for(auto it:dictionary)
	   {
	    int flag=0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(it[0]==board[i][j] and dfs(board,visi,i,j,it,0))
	            {
	                ans.push_back(it);
	                flag=1;
	                break;
	            }
	        }
	        if(flag) break;
	    }
	   }
	   return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends