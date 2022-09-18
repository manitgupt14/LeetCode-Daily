class Solution {
public:
    int trap(vector<int>& arr) {
    int n=arr.size();
    long long ans=0;
    long long tmpans=0;
    long long currmx=arr[0];
    for(int i=1;i<n;i++)
    {
       if(arr[i]<currmx)
       {
           tmpans+=(currmx-arr[i]);
       }
       else if(arr[i]>=currmx)
       {
           ans+=tmpans;
           tmpans=0;
           currmx=arr[i];
       }
    }
    tmpans=0;
    long long mx=arr[n-1];
    for(int i=n-2;i>=0 and mx!=currmx;i--)
    {
      if(arr[i]<mx)
      {
          tmpans+=(mx-arr[i]);
      }
      else if(arr[i]>=mx)
      {
          ans+=tmpans;
          tmpans=0;
          mx=arr[i];
      }
        
    }
    return ans;
    }
};