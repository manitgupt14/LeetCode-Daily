class Solution {
public:
    void findSum(vector<int> &cs,int tt,int sm,int ide,vector<vector<int>> &ans,vector<int> temp)
    {
        if(sm==tt)
        {
            ans.push_back(temp);
            return ;
        }
        if(sm>tt or ide>=cs.size())
            return ;
        
        sm+=cs[ide];
        temp.push_back(cs[ide]);
        findSum(cs,tt,sm,ide,ans,temp);
        temp.pop_back();
        sm-=cs[ide];
        findSum(cs,tt,sm,ide+1,ans,temp);
        
    }
    vector<vector<int>> combinationSum(vector<int>& cs, int tt) {
      vector<vector<int>> ans;
        vector<int> temp;
        findSum(cs,tt,0,0,ans,temp);
        return ans;
    }
};