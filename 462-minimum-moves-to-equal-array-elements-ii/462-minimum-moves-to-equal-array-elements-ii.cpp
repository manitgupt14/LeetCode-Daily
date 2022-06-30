class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int val,ct=0;
        if(nums.size()%2==0)
            val=(nums[nums.size()/2]+nums[nums.size()/2-1])/2;
        else
            val=nums[nums.size()/2];
        for(int i=0;i<nums.size();i++)
        {
            ct+=(abs(val-nums[i]));
        }
    
        
        return ct;
    }
};