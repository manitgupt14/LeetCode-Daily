class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int ct=0;
        unordered_map<string,bool> um;
        for(int i=0;i<words.size();i++)
        {
            int j=0,k=0;
            if(um.find(words[i])!=um.end())
            {
                if(um[words[i]]==true)
                    ct++;
                continue;
            }
            while(s[k]!='\0')
            {
                if(words[i][j]==s[k])
                    j++;
                if(j==words[i].size())
                    break;
                k++;
            }
            if(j==words[i].size())
            { ct++;
              um[words[i]]=true;
            }
            else
                um[words[i]]=false;
        }
        return ct;
    }
};