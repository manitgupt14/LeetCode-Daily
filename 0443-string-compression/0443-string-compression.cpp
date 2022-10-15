class Solution {
public:
    int compress(vector<char>& chars) {
        string ans="";
        
        int ct=0;
        char temp=chars[0];
        for(int i=0;i<chars.size();i++)
        {
            if(temp==chars[i])
            {
                ct++;
            }
            
            else
            {
                ans.push_back(temp);
                if(ct>1)
                    ans+= to_string(ct);
                temp=chars[i];
                ct=1;
                
            }
            
        }
        ans.push_back(temp);
        if(ct>1)
        ans+= to_string(ct);
        for(int i=0;i<ans.size();i++)
            chars[i]=ans[i];
        
        return ans.size();
    }
};