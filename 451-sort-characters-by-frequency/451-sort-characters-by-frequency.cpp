class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        int i=0;
        while(s[i]!='\0')
        {
            mp[s[i]]++;
            i++;
        }
        
        priority_queue<pair<int,char>> pq;
        for(auto it:mp)
        {
            int d=it.second;
            char q=it.first;
            pq.push({d,q});
        }
        
        string ans="";
        
        while(!pq.empty())
        {
            int g=pq.top().first;
            char r=pq.top().second;
            while(g--)
            {
                ans+=r;
            }
            pq.pop();
        }
        
        return ans;
        
    }
};