class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      for(int i=0;i<nums.size();i++)
      {
          if(nums[i]%2==0)
              nums[i]=0;
          else
              nums[i]=1;
      }
       
      unordered_map<int,int> mp;
        int sm=0;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sm+=nums[i];
            if(mp.find(sm-k)!=mp.end())
            {ans+=mp[sm-k];mp[sm]++;}
            else
                mp[sm]+=1;
        }
        
        return ans;  
        
    }
};