class Linkedlist{
    public:
    int data;
    Linkedlist *next;
    Linkedlist()
    {
        this->next=NULL;
    }
    Linkedlist(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    Linkedlist(int data,Linkedlist* next)
    {
        this->data=data;
        this->next=next;
    }
};
class MyCircularDeque {
public:
    int size=0;
    int cap=0;
    Linkedlist *head=NULL;
    MyCircularDeque(int k) {
        size=k;
        cap=k;
    }
    
    bool insertFront(int value) {
        if(size==0) return false;
        if(head==NULL)
        {
            head=new Linkedlist(value);
        }
        else
        {
            head=new Linkedlist(value,head);
        }
        size--;
        return true;
    }
    
    bool insertLast(int value) {
        if(size==0) return false;
        if(head==NULL)
        {
            head=new Linkedlist(value);
            size--;
            return true;
        }
        Linkedlist *tmp=head;
        while(tmp->next!=NULL)
            tmp=tmp->next;
        tmp->next=new Linkedlist(value);
        size--;
        return true;
    }
    
    bool deleteFront() {
        if(head==NULL) return false;
        head=head->next;
        size++;
        return true;
    }
    
    bool deleteLast() {
        if(head==NULL) return false;
        if(head->next==NULL)
        {
            size++;
            head=NULL;
            return true;
        }
        Linkedlist *tmp=head;
        while(tmp->next->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=NULL;
        size++;
        return true;
    }
    
    int getFront() {
        if(head==NULL) return -1;
        return head->data;
    }
    
    int getRear() {
        if(head==NULL) return -1;
        Linkedlist *tmp=head;
        while(tmp->next!=NULL)
            tmp=tmp->next;
        return tmp->data;
    }
    
    bool isEmpty() {
        return size==cap;
    }
    
    bool isFull() {
        return size==0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */