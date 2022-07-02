class Solution {
public:
    int maxArea(int h, int w, vector<int>& ht, vector<int>& vt) {
        ht.push_back(0);
        ht.push_back(h);
        vt.push_back(0);
        vt.push_back(w);
        sort(begin(ht),end(ht));
        sort(begin(vt),end(vt));
        int mx_h=0,mx_v;
        for(int i=1;i<ht.size();i++)
            mx_h=max(ht[i]-ht[i-1],mx_h);
        for(int i=1;i<vt.size();i++)
            mx_v=max(vt[i]-vt[i-1],mx_v);
        return mx_v*1LL*mx_h%1000000007;
    }
};