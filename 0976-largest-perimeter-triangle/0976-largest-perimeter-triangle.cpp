class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        for(int i=2;i<nums.size();i++)
        {
        int a=nums[i-2];
        int b=nums[i-1];
        int c=nums[i];
        if((a+b>c) and (a+c>b) and (b+c>a))
        {
            return a+b+c;
        }
        }
        
        return 0;
    }
};