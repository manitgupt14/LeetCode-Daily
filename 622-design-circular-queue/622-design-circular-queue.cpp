class MyCircularQueue {
public:
    int front=-1,rear=-1;
    int size;
    vector<int> nums;
    MyCircularQueue(int k) {
        size=k;
        nums.clear();
        nums.resize(k);
    }
    
    bool enQueue(int value) {
        if ((front == 0 && rear == size-1) ||
            (rear == (front-1)%(size)))
            return false;
        if(front==-1)
        {
            front=rear=0;
            nums[rear]=value;
        }
        else if (rear == size-1 && front != 0)
        {
        rear = 0;
        nums[rear] = value;
        }
 
      else
       {
        rear++;
        nums[rear] = value;
       }
        return true;
    }
    
    bool deQueue() {
        if(front==-1)
            return  false;
        
        if(front==rear)
            front=rear=-1;
        
        else  if(front==size-1)
            front=0;
        else
            front++;
        return true;
    }
    
    int Front() {
        if(front==-1)
            return  -1;
        return nums[front];
       
    }
    
    int Rear() {
       if(front==-1)
            return  -1;
        return nums[rear];
    }
    
    bool isEmpty() {
        return front==-1 and rear==-1;
    }
    
    bool isFull() {
        return  ((front == 0 && rear == size-1) ||
            (rear == (front-1)%(size-1)));
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */