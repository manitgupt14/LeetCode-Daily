class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> ans;
        int k=0;
        while(k<n+1)
        {
            vector<int> d;
            d.push_back(1);
            for(int i=1;i<k;i++)
            {
                d.push_back(ans[k-1][i-1]+ans[k-1][i]);
            }
            if(k!=0)
                d.push_back(1);
            ans.push_back(d);
            k++;
        }
        return ans[n];
    }
};