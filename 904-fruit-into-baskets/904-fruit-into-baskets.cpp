class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int j=0;
        unordered_map<int,int> mp;
        int ct=0;
        int ans=0;
        for(int i=0;i<fruits.size();i++)
        {
            if(mp.size()==2 and mp.find(fruits[i])==mp.end())
            {
                ans=max(ct,ans); // 2
                while(mp.size()!=1)
                {
                    mp[fruits[j]]--;
                    if(mp[fruits[j]]==0)
                    {
                        mp.erase(mp.find(fruits[j]));
                    }
                    j++;
                    ct--;
                }
            }
            mp[fruits[i]]++;
            ct++;
        }
        ans=max(ct,ans);
        return ans;
    }
};