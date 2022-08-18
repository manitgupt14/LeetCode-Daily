class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
        
        priority_queue<pair<int,int>> pq;
        for(auto it:mp)
        {
          pq.push({it.second,it.first});
        }
        
        int count=0;
        int sum=0;
        while(sum<n/2)
        {
            count++;
            sum+=pq.top().first;
            pq.pop();
        }
        
        return count;
        
    }
};