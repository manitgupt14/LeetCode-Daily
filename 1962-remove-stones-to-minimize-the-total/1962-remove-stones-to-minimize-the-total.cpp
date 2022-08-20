class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sm=0;
        for(auto it:piles)
        {pq.push(it);sm+=it;}
        while(k--)
        {
            int val=pq.top();
            pq.pop();
            sm-=val/2;
            val=val-val/2;
            pq.push(val);
        }
        
        
        return sm;
    }
};