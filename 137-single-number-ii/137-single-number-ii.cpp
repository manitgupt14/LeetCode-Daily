class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int tmp[33]={0};
        int N=arr.size();
        for(int i=0;i<N;i++)
        {
            if(arr[i]<0)
            tmp[32]++;
            long val=abs(arr[i]);
            for(int j=0;j<32;j++)
            { 
                if(val & 1)
                    tmp[j]++;
                val/=2;
            }
        }
        
        long ans=0;
        for(long i=0;i<32;i++)
        {
            if(tmp[i]%3!=0)
           {
            ans+=(1<<i);
           }
        }
        
        if(ans==INT_MAX and tmp[32]%3!=0)
            return INT_MIN;
        
        if(tmp[32]%3!=0)
        ans*=-1;
        
        return ans;
    }
};