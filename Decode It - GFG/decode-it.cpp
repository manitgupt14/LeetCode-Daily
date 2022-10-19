//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{   
public:
    string open(string temp,int ct)
    {
        string ans="";
        while(ct--)
        ans+=temp;
        return ans;
    }
    char decodeIt(string str, int k)
    {
        string temp="";
        int i=0;
        while(str[i]!='\0')
        {
            while(str[i]!='\0' and (str[i]>='a' and str[i]<='z'))
            {
                temp+=str[i];
                i++;
            }
            int nm=0;
            while(str[i]!='\0' and (str[i]>='0' and str[i]<='9'))
            {
                nm=nm*10+(str[i]-'0');
                i++;
            }
            temp=open(temp,nm);
        }
        return temp[k-1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int k;
        cin>>k;
        Solution ob;
        cout << ob.decodeIt(str,k) << endl;
    }
}
// } Driver Code Ends