int binary(vector<int> a,int i,int j,int x)
{
    if(i<=j)
    {
        int mid=(i+j)/2;
        if(a[mid]==x)
            return mid;
        else if(a[mid]>x)
            return binary(a,i,mid-1,x);
        else if(a[mid]<x)
            return binary(a,mid+1,j,x);
        else 
            return -1;
    }
    return -1;
}
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int k;
        if(matrix[0][0]> target || matrix[n-1][m-1]<target)
            return false;
        int i;
        for(i=0;i<n;i++)
        {
            if(matrix[i][0]<=target && matrix[i][m-1]>=target)
                break;
            if(i!=0 && matrix[i-1][m-1]<target && matrix[i][0]>target)
                return false;
        }
        
        k=binary(matrix[i],0,m-1,target);
        if(k==-1)
            return false;
        return true;
        
    }
};