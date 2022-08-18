class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ct=0;
        int sm=0,j=0;
        for(int i=0;i<k;i++)
        {
            sm+=arr[i];
        }
        if(sm/k>=threshold)
            ct++;
        for(int i=k;i<arr.size();i++,j++)
        {
            sm+=arr[i];
            sm-=arr[j];
            if(sm/k>=threshold)
                ct++;
        }
        
        
        return ct;
    }
};