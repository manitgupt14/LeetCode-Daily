class SmallestInfiniteSet {
public:
    int k=1;
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_set<int> us;
    SmallestInfiniteSet() {
        k=1;
    
    }
    
    int popSmallest() {
        if(pq.empty() or k<pq.top())
        {
            return k++;
        }
        if(!pq.empty() and k==pq.top())
        {
            pq.pop();
             us.erase(us.find(k));
            return k++;
        }
        int val=pq.top();
        pq.pop();
        us.erase(us.find(val));
        return val;
    }
    
    void addBack(int num) {
        if(us.find(num)==us.end())
        { us.insert(num);pq.push(num);}
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */