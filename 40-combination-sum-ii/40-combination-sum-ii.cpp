class Solution {
public:
    void findSum(vector<int> &cs,int target,int sm,int ide,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(sm==target)
        {
            ans.push_back(temp);
            return ;
        }
        if(sm>target or ide>=cs.size())
            return ;
        
        
        sm+=cs[ide];
        temp.push_back(cs[ide]);
        findSum(cs,target,sm,ide+1,ans,temp);
        sm-=cs[ide];
        int j=ide;
        while(j<cs.size() and cs[j]==cs[ide]) j++;
        ide=j;
        temp.pop_back();
        findSum(cs,target,sm,ide,ans,temp);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& cs, int target) {
        sort(cs.begin(),cs.end());
        vector<vector<int>> ans;
        vector<int> temp;
        findSum(cs,target,0,0,ans,temp);
        return ans;
    }
};