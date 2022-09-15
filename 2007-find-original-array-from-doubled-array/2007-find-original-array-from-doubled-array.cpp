class Solution {
public:
    vector<int> findOriginalArray(vector<int>& d) {
        map<int,int> mp;
        if(d.size()%2!=0)
            return {};
        for(int i=0;i<d.size();i++)
        {
            mp[d[i]]++;
        }
        vector<int> ans;
        for(auto it:mp)
        {
            if(it.second>0)
            {
            int of=mp[it.first];
            if(mp[it.first*2]>0)
            {
                int v=mp[it.first*2];
                int k;
                if(it.first!=it.first*2)
                k=min(of,v);
                else
                k=of/2; 
                while(k--)
                {ans.push_back(it.first);
                 }
                mp[it.first*2]-=min(of,v);
            }
            }    
        }
        
        if(ans.size()!=d.size()/2) return {};
        return ans;
    }
};