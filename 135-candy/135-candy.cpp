class Solution {
public:
    int candy(vector<int>& ratings) {
       int n=ratings.size();
       vector<int> val(n,1);
        
        for(int i=1;i<n;i++)
            if(ratings[i]>ratings[i-1])
                val[i]=val[i-1]+1;
        
       int ans=val[n-1],tmp=0;
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                tmp=val[i+1]+1;
            else
                tmp=1;
            
            ans+=max(tmp,val[i]);
            val[i]=tmp;
        }
        return ans;
    }
};