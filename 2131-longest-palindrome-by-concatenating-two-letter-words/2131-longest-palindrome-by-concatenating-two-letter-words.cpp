class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
          cin.tie(NULL);
        cout.tie(NULL);
    }
    int longestPalindrome(vector<string>& words) {
        int count=0;
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        
        int ans=0;
        int flag=0;
        for(auto it:mp)
        {
            string temp=it.first;
            if(temp[0]==temp[1])
            {
            if(it.second%2==0)
            {
                ans+=(it.second*2);
            }
            else
            {
                flag=1;
                it.second-=1;
                ans+=(it.second*2);
                it.second=1;
            }
            }
            else
            {
                string tempp="";
                tempp+=temp[1];
                tempp+=temp[0];
                if(mp.find(tempp)!=mp.end())
                {
                 count+=min(it.second,mp[tempp]);
                 it.second=0;
                 mp[tempp]=0;
                }
            }
        }
        
        ans+=count*4;
        if(flag)
            ans+=2;
        return ans;
        
        
        
    }
};