class MyCircularQueue {
    vector<int> cache;
    int size,front,back,len;
public:
    MyCircularQueue(int k) {
        size = k;
        cache.resize(k,-1);
        front = back = -1;
        len = 0;
    }
    
    bool enQueue(int value) {
        if (!isFull()) {
            ++len;
            back = (back+1) % size;
            cache[back] = value;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if (!isEmpty()) {
            --len;
            front = (front+1) % size;
            cache[front] = -1;
            return true;
        }
        return false;
    }
    
    int Front() {
        if (!isEmpty()) {
            return cache[(front+1)%size];
        }
        return -1;
    }
    
    int Rear() {
        if (!isEmpty()) {
            return cache[back];
        }
        return -1;
    }
    
    bool isEmpty() {
        return len == 0;   
    }
    
    bool isFull() {
        return len == size; 
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