class Solution {
public:
    int longestPalindrome(string s) {
       unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        
        int ans=0;
        bool flag=false;
        
        
        for(auto it:mp)
        {
            ans+=(it.second/2);
            if(it.second%2!=0)
                flag=true;
        }
        ans*=2;
        if(flag)
            ans+=1;
        
        return ans;
    }
};