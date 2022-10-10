class Solution {
public:
    string breakPalindrome(string p) {
        if(p.size()==1)
        {
           return "";           
        }
        
        int flag=0;
        for(int i=0;i<p.size();i++)
        {
            if(p[i]>'a' and i!=p.size()/2)
            {
                p[i]='a';
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            p[p.size()-1]='b';
        }
        
        return p;
        
    }
};