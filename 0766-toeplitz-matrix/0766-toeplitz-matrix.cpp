class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
       int n=matrix.size();
       int m=matrix[0].size();
       
       for(int i=0;i<m;i++)
       {
           int r=0,c=i;
           int prev=matrix[r][c];
           r+=1;
           c+=1;
           while(r<n and c<m and prev==matrix[r][c])
               prev=matrix[r++][c++];
           if(r!=n and c!=m) return false;
       }
    
       for(int i=0;i<n;i++)
       {
           int r=i,c=0;
           int prev=matrix[r][c];
           r+=1;
           c+=1;
           while(r<n and c<m and prev==matrix[r][c])
               prev=matrix[r++][c++];
           if(r!=n and c!=m) return false;
       }
       return true;
    }
};