
class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    int calval(unordered_map<int,int> &mp,int i)
    {
        if(mp.find(i)!=mp.end())
            return mp[i];
        if(i%2!=0)
        mp[i]=calval(mp,3*i+1)+1;
        else
            mp[i]=calval(mp,i/2)+1;
        return mp[i];
    }
    int getKth(int lo, int hi, int k) {
        unordered_map<int,int> mp;
        mp[0]=0;
        mp[1]=0;
        mp[2]=1;
        for(int i=4;i<1002;i*=2)
        {
            mp[i]=mp[i/2]+1;
        }
        
        for(int j=1002;j>=3;j--)
        {
            if(mp.find(j)==mp.end())
            {
                mp[j]=calval(mp,j);
            }
        }
        
        vector<vector<int>> vp;
        for(int i=lo;i<=hi;i++)
        {
            vp.push_back({mp[i],i});
        }
        sort(vp.begin(),vp.end(),cmp);
        return vp[k-1][1];
    }
};