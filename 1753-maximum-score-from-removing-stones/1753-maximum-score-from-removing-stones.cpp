class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        int ct=0;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        while(pq.size()>=2)
        {
            int val=pq.top();
            pq.pop();
            int val2=pq.top();
            pq.pop();
            val--;
            val2--;
            if(val>0)
                pq.push(val);
            if(val2>0)
                pq.push(val2);
            ct++;
        }
        return ct;
    }
};

