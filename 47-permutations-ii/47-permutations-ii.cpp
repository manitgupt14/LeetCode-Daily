class Solution {
public:
    void permute(vector<int> nums,int ide,vector<vector<int>> &ans)
    {
        if(ide>=nums.size())
        {
            if(find(ans.begin(),ans.end(),nums)==ans.end(
))
            ans.push_back(nums);
        return ;
        }
         for(int i=ide;i<nums.size();i++)
         {
             if(i>ide and nums[i]==nums[ide])
                 continue;
             swap(nums[i],nums[ide]);
             permute(nums,ide+1,ans);
            // swap(nums[i],nums[ide]);
         }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(begin(nums),end(nums));
        permute(nums,0,ans);
        return ans;
    }
};