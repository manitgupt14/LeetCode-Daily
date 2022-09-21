class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& ns, vector<vector<int>>& qs) {
        int n=qs.size();
        vector<int> ans(n);
        int sm=0;
        for(int i=0;i<ns.size();i++)
        if(ns[i]%2==0)
            sm+=ns[i];
        
        for(int i=0;i<n;i++)
        {
            int vl=qs[i][0];
            int id=qs[i][1];
            
            if(ns[id]%2==0)
            {
                sm-=ns[id];
                ns[id]+=vl;
                if(ns[id]%2==0)
                    sm+=ns[id];
            }
            else
            {
                ns[id]+=vl;
                if(ns[id]%2==0)
                    sm+=ns[id];
            }
            ans[i]=sm;
            
        }
        
        return ans;
    }
};