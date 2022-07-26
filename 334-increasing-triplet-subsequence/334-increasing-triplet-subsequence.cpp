class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(temp.back()<nums[i])
                temp.push_back(nums[i]);
            else
            {
             int qwe=-1;
        int low=0,high=temp.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(temp[mid]==nums[i])
            {qwe=mid;break;}
            else if(temp[mid]<nums[i])
                low=mid+1;
            else
                high=mid-1;
        }
        if(qwe==-1)
            temp[low]=nums[i];}
        }
        return temp.size()>2;
        
    }
};