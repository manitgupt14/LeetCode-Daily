class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        unordered_set<string> us;
        for(auto it:d)
        {
            us.insert(it);
        }
        
        string ans="";
        string tmp="";
        int i=0;
        while(s[i]!='\0')
        {
            if(s[i]==' ')
            {
                ans+=tmp;
                ans+=" ";
                tmp="";
                i++;
            }
            tmp.push_back(s[i]);
            if(us.find(tmp)!=us.end())
            {
                while(i<s.size() and s[i]!=' ')
                    i++;
            }
            else
                i++;
        }
        ans+=tmp;
        return ans;
    }
};