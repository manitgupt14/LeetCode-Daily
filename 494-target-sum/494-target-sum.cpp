class Solution {
public:
    int solve(vector<int> &nums,int target,int idex)
    {
        if(target==0 and idex>=nums.size())
            return 1;
        
        if(idex>=nums.size())
            return 0;
        
        return solve(nums,target+nums[idex],idex+1) +  solve(nums,target-nums[idex],idex+1);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int val=solve(nums,target,0);
        return val;
    }
};