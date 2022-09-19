class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& ps) {
        int n=ps.size();
        vector<vector<string>> vp(n);
        unordered_map<string,vector<string>> mp;
        int i=0;
        for(auto it:ps)
        {
            string tmp;
            stringstream ss(it);
            while(getline(ss,tmp,' '))
            {
             vp[i].push_back(tmp);   
            }
            i++;
        }
        // for(auto it:vp)
        // {
        //     for(auto i:it)
        //         cout<<i<<" ";
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<vp[i].size();j++)
            {
                int k=0;
                while(vp[i][j][k]!='(')
                    k++;
                string la=vp[i][j].substr(0,k);
                string va=vp[i][j].substr(k);
                string fin=vp[i][0]+"/"+la;
                mp[va].push_back(fin);
            }
        }
        vector<vector<string>> ans;
        for(auto it:mp)
        {
            if(it.second.size()>1)
            ans.push_back(it.second);
        }
        return ans;
    }
};