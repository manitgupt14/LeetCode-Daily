//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findstring(string &s,int &i)
    {
        string val="";
        while(s[i]>='0' and s[i]<='9') 
            val+=s[i++];
        
        int ct=stoi(val);
        string temp="";
        i++;
        while(s[i]!=']')
        {
           if(s[i]>='0' and s[i]<='9')
            {
                string zw=findstring(s,i);
                temp+=zw;
            }
            else
                temp+=s[i];
            i++;  
        }
            
        string ans="";
        while(ct--)
            ans+=temp;
        return ans;
    }
    string decodedString(string s){
        string ans="";
        int i=0;
        while(s[i]!='\0')
        {
            if(s[i]>='0' and s[i]<='9')
            {
                string temp=findstring(s,i);
                ans+=temp;
            }
            else
                ans+=s[i];
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends