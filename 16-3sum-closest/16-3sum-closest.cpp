class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int ans=1e5;
        for(int i=0;i<nums.size()-2;i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                int sm=nums[i]+nums[j]+nums[k];
                if(abs(sm-target)<abs(ans-target))
                    ans=sm;
                if(sm==target)
                {
                return target;
                while(j<k and nums[j]==nums[j-1]) j++;
                while(j<k and nums[k]==nums[k-1]) k--;
                j++;
                k--;
                }
                else if(sm>target)
                    k--;
                else
                    j++;
            }
        }
            
        return ans;
    }
};