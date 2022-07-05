class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
         unordered_set<int> un;
       int n=arr.size();
       for(int i=0;i<n;i++)
       un.insert(arr[i]);
       
       
       vector<int> unil;
       
       for(auto it:un)
       {
           int r=it;
           if(un.find(r-1)==un.end())
           {
               unil.push_back(r);
           }
       }
       
       unordered_map<int,int> unq;
       for(int i=0;i<unil.size();i++)
       {
           unq[unil[i]]=1;
       }
       
       for(int i=0;i<unil.size();i++)
       {
           int val=unil[i];
           auto ir=un.find(val);
           un.erase(ir);
           
           while(un.find(val+unq[val])!=un.end())
           {
               auto ik=un.find(val+unq[val]);
               un.erase(ik);
               unq[val]++;
           }

       }
       
       int maxlength=0;
       for(auto it:unq)
       {
           maxlength=max(maxlength,it.second);
       }
        
        return maxlength;
        
    }
};