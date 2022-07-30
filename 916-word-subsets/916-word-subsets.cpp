class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        int n=w2.size();
        vector<vector<int>> hash(n,vector<int> (26,0));
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<w2[i].size();j++)
          hash[i][w2[i][j]-'a']++;    
        }
        int hass[26]={0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                hass[j]=max(hass[j],hash[i][j]);
            }
        }
        
        vector<string> ans;
        
        for(int i=0;i<w1.size();i++)
        {
            int hs[26]={0};
            for(int j=0;j<w1[i].size();j++)
                hs[w1[i][j]-'a']++;
            
            bool tmp=true;
            
            for(int j=0;j<26;j++)
            {
                if(hs[j]<hass[j])
                {
                    tmp=false;
                    break;
                }
            }
            
            if(tmp)
                ans.push_back(w1[i]);
        }
        
        return ans;
    }
};