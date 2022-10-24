class Solution {
    private:
    int solve(vector<string> &arr,int i,string tmp)
    {
        if(i>=arr.size())
        {
            return tmp.size();
        }
        
        vector<int> tmpp(26,0);
        for(auto it:tmp)
        {
            tmpp[it-'a']++;
        }
        bool flg=0;        
        for(auto it:arr[i])
        {
            if(tmpp[it-'a']>0)
            {
                flg=1;
                break;
            }
            tmpp[it-'a']++;
        }
        if(!flg)
        {
            return max(solve(arr,i+1,tmp+arr[i]) , solve(arr,i+1,tmp));
        }
        return solve(arr,i+1,tmp);
        
    }
public:
    int maxLength(vector<string>& arr) {
        int ans=solve(arr,0,"");
        return ans;
    }
};