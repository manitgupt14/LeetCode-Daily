class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> d;
        sort(intervals.begin(),intervals.end());
        vector<int> l;
        l=intervals[0];
        int f=l[0],z=l[1];
        for(int i=1;i<intervals.size();i++)
        {
            l=intervals[i];
            if(l[0]>=f && l[0]<=z)
            { if(l[1]>z)
                z=l[1];}
            else if(l[0]>f && l[0]>z)
            {
                d.push_back({f,z});
                f=l[0];
                z=l[1];
            }
        }
        d.push_back({f,z});
        return d;}
};