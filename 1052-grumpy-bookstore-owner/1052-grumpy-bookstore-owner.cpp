class Solution {
public:
    int maxSatisfied(vector<int>& cs, vector<int>& gy, int ms) {
        int ans=0;
        for(int i=0;i<cs.size();i++)
        {
            if(gy[i]==0)
                ans+=cs[i];
        }
        int mxsm=0;
        int tmpsm=0,j=0;
        for(int i=0;i<ms;i++)
        {
            if(gy[i]==1)
            {
                tmpsm+=cs[i];
            }
        }
        mxsm=tmpsm;
        for(int i=ms;i<gy.size();i++,j++)
        {
            if(gy[i]==1)
                tmpsm+=cs[i];
            if(gy[j]==1)
                tmpsm-=cs[j];
            mxsm=max(tmpsm,mxsm);
        }
        
        return mxsm+=ans;
        
        
    }
};