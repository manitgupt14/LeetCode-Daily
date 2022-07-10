class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
              vector<long long int> le(n);
       vector<long long int> re(n);
       vector<int> ans(n,1);
       
       if(nums.size()==1)
       return ans;
       for(int i=0;i<nums.size();i++)
       {
           if(i==0)
           le[i]=nums[i];
           
           else 
           le[i]=le[i-1]*nums[i];
       }
       
       for(int i=nums.size()-1;i>=0;i--)
       {
           if(i==nums.size()-1)
           re[i]=nums[i];
           
           else
           re[i]=re[i+1]*nums[i];
       }
       
       
       
       for(int i=0;i<n;i++)
       {
           if(i==0)
           ans[i]=re[i+1];
           else if(i==n-1)
           ans[i]=le[i-1];
           else
           ans[i]=le[i-1]*re[i+1];
       }
       return ans;
       
    }
};