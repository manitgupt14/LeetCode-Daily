class Solution {
    private :
    bool check(unordered_map<char,int> &fix,unordered_map<char,int> &tmp)
    {
        for(auto it:fix)
        {
            if(fix[it.first]>tmp[it.first])
                return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())
            return "";
        unordered_map<char,int> fix,mp;
        for(int i=0;i<t.size();i++)
        {
            fix[t[i]]++;
        }
        int ans_start=s.size()+100;
        int mn_size=INT_MAX;
        int j=0;
        while(j<s.size() and fix.find(s[j])==fix.end()) j++;
        
        int i=j;
        while(s[i]!='\0')
        {
            if(fix.find(s[i])!=fix.end())
                mp[s[i]]++;
            if(fix[s[j]]<mp[s[j]])
            {
             mp[s[j]]--;
             j++;
             while(j<i and fix.find(s[j])==fix.end() or mp[s[j]]>fix[s[j]]) 
             {
                 if(fix.find(s[j])!=fix.end())
                 {
                     mp[s[j]]--;
                 }
                 j++;
             } 
                
            }
            if(fix.size()==mp.size() and check(fix,mp))
            {
                if(mn_size>i-j+1)
                {
                    mn_size=i-j+1;
                    ans_start=j;
                }
            }
            i++;
        }
        if(ans_start==s.size()+100)
            return "";
        return s.substr(ans_start,mn_size);
        
    }
};