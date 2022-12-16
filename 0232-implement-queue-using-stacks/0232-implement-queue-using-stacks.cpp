class MyQueue {
public:
    stack<int> st;
    stack<int> ts;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st.empty())
        {
            ts.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!ts.empty())
        {
            st.push(ts.top());
            ts.pop();
        }
    }
    
    int pop() {
        int vl=st.top();
        st.pop();
        return vl;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */