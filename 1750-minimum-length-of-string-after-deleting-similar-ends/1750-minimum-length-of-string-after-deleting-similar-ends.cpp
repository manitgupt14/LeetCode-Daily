class Solution {
public:
    int minimumLength(string s) {
       int i=0,j=s.size()-1;
       while(i<j)
       {
           if(s[i]!=s[j])
               break;
           while(i<=j and s[i]==s[j])
               i++;
           
           while(i<=j and s[i-1]==s[j])
               j--;
               
       }
        
       if(i>j)
           return 0;
       return j-i+1;
    }
};