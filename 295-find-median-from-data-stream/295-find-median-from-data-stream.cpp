class MedianFinder {
public:
    priority_queue<int> pq,qp; //  pq is max heap, qp is min heap
    double curr_median=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq.size()>qp.size())
        {
            pq.push(num);
            qp.push(-pq.top());
            pq.pop();
            curr_median=((pq.top()-qp.top())*1.0)/2;
        }
        else
        {
            pq.push(num);
            qp.push(-pq.top());
            pq.pop();
            pq.push(-qp.top());
            qp.pop();
            curr_median=pq.top();
        }
        
    }
    
    double findMedian() {
        return curr_median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */