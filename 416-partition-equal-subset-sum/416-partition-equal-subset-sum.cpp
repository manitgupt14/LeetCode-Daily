class Solution {
public:
    bool find(int sm,vector<int> &nums,int idex,vector<vector<int>> &dp)
    {        
        if(idex>=nums.size())
        {
            if(sm==0)
            return true;
            else
                return false;
        }
        else if(sm<0)
            return false;
        
        if(dp[idex][sm]!=-1)
            return dp[idex][sm];
        
        if(nums[idex]<=sm)
        {dp[idex][sm]=find(sm-nums[idex],nums,idex+1,dp) || find(sm,nums,idex+1,dp);
        return dp[idex][sm];}
        
        
        else if(nums[idex]>sm)
        {dp[idex][sm]=find(sm,nums,idex+1,dp);
        return dp[idex][sm];}
        
        return true;
    }
    bool canPartition(vector<int>& nums) {
        int sm=0;
        for(int i=0;i<nums.size();i++)
        {
            sm+=nums[i];    
        }
        
        if(sm%2!=0)
            return false; 
        
        vector<vector<int>> dp(nums.size()+1,vector<int> (sm/2+1,-1));
        return find(sm/2,nums,0,dp);
        
    }
};