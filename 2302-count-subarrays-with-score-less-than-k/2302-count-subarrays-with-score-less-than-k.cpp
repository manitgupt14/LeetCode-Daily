class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        long long i=0,j=0,ans=0,sum=nums[0];
        
        long long ct=0;
        long long tm=0;
        while(i<nums.size() and j<nums.size())
        {
            
            if(sum*(j-i+1)<k)
            {
                j++;
                if(j>=i)
                {
                    ans+=(j-i);
                }
                
                if(j<nums.size())
                { sum+=nums[j];}
            }
            
            else {
            sum -= nums[i];
                i++;
            }
        }
        return ans;
        
    }
};