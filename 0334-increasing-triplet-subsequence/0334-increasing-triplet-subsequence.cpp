class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mx1=INT_MAX,mx2=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=mx1)
            {
                mx1=nums[i];
            }
            else if(nums[i]<=mx2)
            {
                mx2=nums[i];
            }
            else
                return true;
        }
        return false;
    }
};