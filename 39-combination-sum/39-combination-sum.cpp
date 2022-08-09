void solve(int target,vector<int> &candidates,int i,vector<vector<int>> &ans,vector<int> &temp)
{
    if(i>=candidates.size())
    {
        return ;
    }
    if(target==0)
    {
        ans.push_back(temp);
        return ;
    }
    
    else if(target<0)
    return ;   
    
    vector<int> k=temp;
    k.push_back(candidates[i]);
    solve(target-candidates[i],candidates,i,ans,k);
    solve(target,candidates,i+1,ans,temp);
    
    return ;
}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(target,candidates,0,ans,temp);
        
        return ans;
    }
};