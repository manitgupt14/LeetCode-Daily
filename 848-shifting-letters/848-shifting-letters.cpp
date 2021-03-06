class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
       int n=shifts.size();
        shifts[n-1]=shifts[n-1]%26;
       for(int i=n-2;i>=0;i--)
       {
           shifts[i]+=shifts[i+1];
           shifts[i]=shifts[i]%26;
       }
        for(int i=0;i<s.size();i++)
        {
            int val=s[i]-'a';
            val= (val+shifts[i])%26;
            s[i]=val + 'a';
        }
        
        return s;
    }
};