class Solution {
public:
    bool canTransform(string start, string target) {
        int n=start.size();
        vector<pair<int,int>> v;
        vector<pair<int,int>> v2;
        for(int i=0;i<n;i++)
        {
            if(start[i]=='L')
                v.push_back({2,i});
            else if(start[i]=='R')
                v.push_back({3,i});
        }
        
        for(int i=0;i<n;i++)
        {
            if(target[i]=='L')
                v2.push_back({2,i});
            else if(target[i]=='R')
                v2.push_back({3,i});
        }
        if(v.size()!=v2.size())
            return false;
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first!=v2[i].first)
            {
                return false;
            }
            if(v[i].first==2 and v[i].second-v2[i].second<0)
                return false;
             if(v[i].first==3 and v[i].second-v2[i].second>0)
                return false;
        }
        return true;
    }
};