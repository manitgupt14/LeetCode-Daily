class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        bool flag=true;
       for(int i=0;i<matrix[0].size();i++)
       {
           int r=0,c=i;
           int k=ans.size();
           while(r<matrix.size() and c>=0)
           {
               ans.push_back(matrix[r][c]);
               c--;
               r++;
           }
           if(flag)
           {
               reverse(ans.begin()+k,ans.end());
               flag=false;
           }
           else
               flag=true;
       }
       for(int i=1;i<matrix.size();i++)
       {
           int r=i,c=matrix[0].size()-1;
           int k=ans.size();
           while(r<matrix.size() and c>=0)
           {
               ans.push_back(matrix[r][c]);
               c--;
               r++;
           }
           if(flag)
           {
               reverse(ans.begin()+k,ans.end());
               flag=false;
           }
           else
               flag=true;
       }
       return ans;
    }
};