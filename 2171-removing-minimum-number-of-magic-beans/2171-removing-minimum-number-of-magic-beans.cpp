class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long sm=0;
        long long lsm=0; 
        sort(beans.begin(),beans.end());
        
        for(int i=0;i<beans.size();i++)
            sm+=beans[i];
        
        int n=beans.size();
        
        long long ans=LONG_MAX;
        
        for(int i=0;i<n;i++)
        {
          long long tmp=0;
          tmp+=(sm-(n-i)*(long long)beans[i]);   
          lsm+=beans[i];
          ans=min(tmp,ans);
        }
        
        
        return ans;
        
        
    }
};