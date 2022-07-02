class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
            arr[i]= (arr[i]%2!=0);
          
    long ans=0;
    long odd_sum=0;
    long even_sum=0;
    for(auto it:arr)
    {
        if(it%2==0)
            even_sum++;
        else
        {
            int temp=even_sum;
            even_sum=odd_sum;
            odd_sum=temp+1;
        }
        ans+=odd_sum;
        ans%=1000000007;
    }
        
        return ans;
    }
};