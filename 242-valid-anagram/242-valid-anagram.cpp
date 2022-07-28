class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        int i=0;
        while(s[i]!='\0')
        {
            v[s[i]-'a']++;
            i++;
        }
        int j=0;
        while(t[j]!='\0')
        {
            v[t[j]-'a']--;
            j++;
        }
        for(i=0;i<26;i++)
        {
            if(v[i]!=0)
                return false;
        }
        return true;
        
        
    }
};