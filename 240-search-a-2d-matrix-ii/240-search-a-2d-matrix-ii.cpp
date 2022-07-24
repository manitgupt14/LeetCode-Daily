class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int x) {
         int row=0,col=matrix[0].size()-1;
        while(row<matrix.size() and col>=0)
        {
            if(matrix[row][col]>x)
            col--;
            else if(matrix[row][col]==x)
            return true;
            else
            row++;
        }
        return false;
    }
};