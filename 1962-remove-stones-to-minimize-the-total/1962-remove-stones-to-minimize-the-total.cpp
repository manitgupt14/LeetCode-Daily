class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto it:piles)
            pq.push(it);
        while(k--)
        {
            int val=pq.top();
            pq.pop();
            val=val-val/2;
            pq.push(val);
        }
        
        int sm=0;
        while(!pq.empty())
        {   sm+=pq.top();
            pq.pop();
        }
        return sm;
    }
};