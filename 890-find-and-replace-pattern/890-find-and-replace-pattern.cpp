class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        unordered_map<char,int> mp;
        int m=pattern.size();
        int i=0;
        string s;
        while(pattern[i]!='\0')
        {
            if(mp.find(pattern[i])==mp.end())
            {
                mp[pattern[i]]=i;
                s+=to_string(i);
            }
            else
            {
                s+=to_string(mp[pattern[i]]);
            }
            i++;
        }
        vector<string> ans;
        for(i=0;i<words.size();i++)
        {
               string tmp="";
               int k=0;
               unordered_map<char,int> kp;
               while(words[i][k]!='\0')
                     {
                         if(kp.find(words[i][k])==kp.end())
                         {  kp[words[i][k]]=k;
                            tmp+=to_string(k);
                         }
                         else
                             tmp+=to_string(kp[words[i][k]]);
                         k++;
                     }
            if(tmp==s)
                ans.push_back(words[i]);
                      
        }
        
        
        return ans;
                     
        }     
};