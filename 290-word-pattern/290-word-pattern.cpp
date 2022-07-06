class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string> tmp;
        while(getline(ss,s,' '))
        {
            tmp.push_back(s);
        }
        unordered_map<char,int> um;
        unordered_map<string,int> us;
        
        if(tmp.size()!=pattern.size())
        {
            return false;
        }
        
        
        for(int i=0;i<tmp.size();i++)
        {
            if(us.find(tmp[i])==us.end())
                us[tmp[i]]=i;
            if(um.find(pattern[i])==um.end())
                um[pattern[i]]=i;
            if(us[tmp[i]]!=um[pattern[i]])
                return false;
        }
        return true;
        
        
        return true;
        
    }
};