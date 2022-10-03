class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int j=0;
        n=target.size();
        for(int i=1;i<=target[n-1];i++)
        {
            ans.push_back("Push");
            if(target[j]!=i)
            {
                ans.push_back("Pop");
            }
            else
                j++;
        }
        
        return ans;
    }
};