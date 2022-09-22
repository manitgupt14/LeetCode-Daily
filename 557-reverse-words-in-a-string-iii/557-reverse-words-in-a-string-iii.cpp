class Solution {
public:
    string reverseWords(string s) {
       stringstream ss(s);
        string ans="";
        while(getline(ss,s,' '))
              {
                  reverse(s.begin(),s.end());
                  ans+=s+" ";
                  }
        ans.pop_back();
        return ans;
    }
};