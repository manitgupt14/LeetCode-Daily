class Solution {
public:
    int firstUniqChar(string s) {
      for(int i=0;i<s.size();i++)
        {
            int j;
            for(j=0;j<s.size();j++)
            {
                if(s[i]==s[j] and i!=j)
                    break;
            }
            if(j==s.size())
                return i;
        }
        
        return -1;  
        
    }
};