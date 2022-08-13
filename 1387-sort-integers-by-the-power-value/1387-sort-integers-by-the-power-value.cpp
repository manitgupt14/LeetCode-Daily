class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    int countdigit(int n)
    {
        int ct=0;
        while(n>1)
        {
            if(n%2==0)
                n=n/2;
            else
                n=3*n+1;
            ct++;
        }
        return ct;
    }
    int getKth(int lo, int hi, int k) {
        vector<vector<int>> vp;
        for(int i=lo;i<=hi;i++)
        {
            int ct=countdigit(i);
            vp.push_back({ct,i});
        }
        sort(vp.begin(),vp.end(),cmp);
        return vp[k-1][1];
        
    }
};