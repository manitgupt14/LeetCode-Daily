class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()==2)
            return nums;
        
        int val=0;
        for(auto it:nums)
            val^=it;
        
        int v;
        for(int i=0;i<32;i++)
        {
            if(val & (1<<i))
            {
                v=(1<<i);
                break;
            }
        }
        
        int tmp1=0;
        int tmp2=0;
        for(auto it:nums)
        {
            if(it  & v)
            {
             tmp1^=it;   
            }
            else
            {
                tmp2^=it;
            }
        }
        
        int ans_a=val^tmp1;
        int ans_b=val^tmp2;
        
        return {ans_a,ans_b};
        
    }
};