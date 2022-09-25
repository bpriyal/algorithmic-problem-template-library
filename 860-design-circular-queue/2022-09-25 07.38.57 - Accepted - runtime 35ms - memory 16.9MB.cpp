class MyCircularQueue {
    vector<int> cache;
    int front;
    int rear;
    int size;
    int len;
public:
    MyCircularQueue(int k) {
        cache.resize(k);
        size = k;
        front = -1;
        rear = -1;
        len = 0;
    }
    
    bool enQueue(int value) {
        if (!isFull()) {
            ++len;
            rear = (rear + 1) % size;
            cache[rear] = value;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if (!isEmpty()) {
            --len;
            front = (front + 1) % size;
            cache[front] = -1;
            return true;
        }
        return false;
    }
    
    int Front() {
        if (!isEmpty()) {
            return cache[(front + 1) % size];
        }
        return -1;
    }
    
    int Rear() {
        if (!isEmpty()) {
            return cache[rear];
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