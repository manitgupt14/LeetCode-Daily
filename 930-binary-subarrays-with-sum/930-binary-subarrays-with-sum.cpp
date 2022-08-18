class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
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