class Solution {
public:
  
    bool calculateDays(vector<int> &weights,int midValue,int days)
    {
        
        int ct=1;
        int tsm=0;
        for(int i=0;i<weights.size();i++)
        {
            if(tsm+weights[i] > midValue)
            {
                tsm=0;
                ct++;
            }
            tsm+=weights[i];
        }
        
        return ct<=days;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans=INT_MAX;
        
        int tweight=0,mxcap=0;
        for(int i=0;i<weights.size();i++)
        {tweight+=weights[i];mxcap=max(weights[i],mxcap);}
        
        
        int low=0,high=tweight;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(mid >=mxcap and calculateDays(weights,mid,days))
            {
                ans=min(mid,ans);
                high=mid-1;
            }
            else
                low=mid+1;
            
        }
        
        return ans;
    }
};