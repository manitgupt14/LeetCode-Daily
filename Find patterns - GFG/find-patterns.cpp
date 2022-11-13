//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string s, string w){
        vector<bool> vis(s.size(),false);
        vector<int> temp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==w[0])
            temp.push_back(i);
        }
        int ct=0;
        for(int i=0;i<temp.size();i++)
        {
            int k=temp[i];
            int j=0;
            while(k<s.size() and j<w.size())
            {
                if(s[k]==w[j] and !vis[k])
                {
                    j++;
                    vis[k]=true;
                }
                k++;
            }
            if(j==w.size())
            {
                ct++;
            }
            else
            break;
        }
        return ct;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends