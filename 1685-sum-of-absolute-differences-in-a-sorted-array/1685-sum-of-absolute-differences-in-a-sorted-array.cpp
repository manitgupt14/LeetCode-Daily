class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        int tsum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
            tsum+=nums[i];
        int lsum=0;
        
        for(int i=0;i<n;i++)
        {
            int val= ((2*i-n)*1LL*nums[i]) - (2*lsum) + tsum;
            ans.push_back(val);
            lsum+=nums[i];
        }
        
        return ans;
    }
};