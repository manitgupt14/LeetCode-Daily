class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int,string> mp;
        for(int i=0;i<strs.size();i++)
            mp[i]=strs[i];
        unordered_map<string,vector<string>> mpp;
        for(int i=0;i<strs.size();i++)
        {
            sort(strs[i].begin(),strs[i].end());
            mpp[strs[i]].push_back(mp[i]);
        }
        
        vector<vector<string>> ans;
        for(auto it:mpp)
            ans.push_back(it.second);
        return ans;
        }
};