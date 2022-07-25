class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
            {
                low=mid+1;
            }
        }
        if(ans==-1)
            return {-1,-1};
        
        int ansb=-1;
        low=0,high=nums.size()-1;
        
        while(low<=high)
        {
             int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                ansb=mid;
                low=mid+1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
            {
                low=mid+1;
            }
        }
        
        return {ans,ansb};
        
    }
};