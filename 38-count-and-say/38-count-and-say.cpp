class Solution {
public:
    string countAndSay(int n) {
     if(n==1)
        return "1";
    string val=countAndSay(n-1);
    int ct=1;
    string ans="";
    for(int i=1;i<val.size();i++)
    {
        if(val[i]==val[i-1])
            ct++;
        else
        {
            ans+=to_string(ct);
            ans.push_back(val[i-1]);
            ct=1;
        }
    }
    ans+=to_string(ct);
    ans.push_back(val[val.size()-1]);
    return ans;
    }
};