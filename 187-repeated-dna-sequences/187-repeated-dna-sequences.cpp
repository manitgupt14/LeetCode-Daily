class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10)
            return {};
        unordered_map<string,int> um;
        string tmp="";
        for(int i=0;i<10;i++)
        {
            tmp = s[i]+tmp;
        }
        
        um[tmp]++;
        
        for(int i=10;i<s.size();i++)
        {
            tmp.pop_back();
            tmp= s[i]+tmp;
            um[tmp]++;
        }
        
        vector<string> ans;
        
        for(auto it:um)
        {
            if(it.second>1)
            {
                string val=it.first;
                reverse(val.begin(),val.end());
                ans.push_back(val);
            }
        }
        
        return ans;
    }
};