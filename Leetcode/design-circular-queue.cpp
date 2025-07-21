// coding challenge: https://leetcode.com/problems/design-circular-queue/
 
Solution 1: Using a dynamic array
=================================
class MyCircularQueue {
public:

    int* q;
    int size, ctr, head, tail;

    MyCircularQueue(int k) {
        // initialize
        size = k;
        q = new int[size];
        ctr = 0;
        head = 0;
        tail = -1;
    }
    
    bool enQueue(int value) {
        if(isFull() == true){
            return false;
        }
        
        tail = (tail + 1) % size; // wrap around
        q[tail] = value;
        ctr++;

        return true;
    }
    
    bool deQueue() {
        if(isEmpty() == true){
            return false;
        }

        head = (head + 1) % size; // wrap around
        ctr--;
         
        return true;
    }
    
    int Front() {
        if(isEmpty() == true){
            return -1;
        }
        else{
            return q[head];
        }
    }
    
    int Rear() {
        if(isEmpty() == true){
            return -1;
        }
        else{
            return q[tail];
        }
    }
    
    bool isEmpty() {
        if(ctr == 0){
            return true;
        }else{
            return false;
        }
    }
    
    bool isFull() {
        if(ctr == size){
            return true;
        }else{
            return false;
        }
    }

    ~MyCircularQueue() {
        delete [] q;
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

Solution 2: Using a deque
====================
class MyCircularQueue {
public:

    deque<int> q;
    int size;

    MyCircularQueue(int k) {
        size = k;
    }

    bool enQueue(int value) {
        if(isFull() == true){
        return false;
    }

    q.push_back(value);
        return true;
    }

    bool deQueue() {
        if(isEmpty() == true){
        return false;
    }

    q.pop_front();
        return true;
    }

    int Front() {
        if(isEmpty() == true){
            return -1;
        }
        else{
            return q.front();
        }
    }

    int Rear() {
        if(isEmpty() == true){
            return -1;
        }
        else{
            return q.back();
        }
    }

    bool isEmpty() {
    return q.empty();
}

    bool isFull() {
        if(q.size() == size){
            return true;
        }else{
            return false;
        }
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
