class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+(high-low)/2);
            bool a=true;
            bool b=true;
            if(mid>0 and nums[mid]<nums[mid-1])
                a=false;
            if(mid<nums.size()-1 and nums[mid]<nums[mid+1])
                b=false;
            if(a and b)
                return mid;
            if((!a))
                high=mid-1;
            else if((!b))
                low=mid+1;
        }
        return 0;
    }
};