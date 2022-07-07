class Solution {
public:
    void sortColors(vector<int> &v) {
        
       int low,mid,high;
    low=mid=0,high=v.size()-1;
    int i=0;
    while(mid<=high)
    {
        if(v[mid]==0)
        {
            swap(v[low],v[mid]);
            low++;mid++;
        }
        else if(v[mid]==1)
        {
            //swap(v[mid],v[i]);
            mid++;
        }
        else
        {
            swap(v[high],v[mid]);
            high--;
        }
    }
        
        
    }
};