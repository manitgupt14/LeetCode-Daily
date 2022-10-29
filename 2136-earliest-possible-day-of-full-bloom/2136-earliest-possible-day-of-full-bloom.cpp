class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {   
        return a.second > b.second;
    }
    int earliestFullBloom(vector<int>& pt, vector<int>& gt){
        vector<pair<int,int>> vp;
        for(int i=0;i<pt.size();i++)
        {
            vp.push_back({pt[i],gt[i]});
        }
        sort(vp.begin(),vp.end(),cmp);
        
        int mx=0;
        int mxpl=0;
        for(int i=0;i<vp.size();i++)
        {
            mxpl+=vp[i].first;
            mx=max(mxpl+vp[i].second,mx);
        }
        return mx;
    }
};