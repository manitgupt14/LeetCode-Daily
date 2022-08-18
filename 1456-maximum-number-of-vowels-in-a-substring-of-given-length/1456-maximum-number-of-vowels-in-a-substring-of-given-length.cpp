class Solution {
public:
    int maxVowels(string s, int k) {
        int mx=0;
        int ct=0,j=0;
        for(int i=0;i<k;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u')
                ct++;
        }
        mx=ct;
        for(int i=k;i<s.size();i++,j++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u')
                ct++;
            if(s[j]=='a' || s[j]=='e' || s[j]=='o' || s[j]=='i' || s[j]=='u')
                ct--;
            mx=max(ct,mx);
        }
        
        return mx;
    }
};