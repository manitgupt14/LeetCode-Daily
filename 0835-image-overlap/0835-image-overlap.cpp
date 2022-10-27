class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans=0;
        
        vector<pair<int,int>> v1,v2;
        for(int i=0;i<img1.size();i++)
        {
            for(int j=0;j<img1[0].size();j++)
            {
                if(img1[i][j]==1)
                    v1.push_back({i,j});
                if(img2[i][j]==1)
                    v2.push_back({i,j});
            }
        }
        map<pair<int,int>,int> mp;
        for(auto it:v1)
        {
            for(auto i:v2)
            {
                mp[{it.first-i.first,it.second-i.second}]++;
                ans=max(ans, mp[{it.first-i.first,it.second-i.second}]);
            }
        }
        return ans;
        
    }
};