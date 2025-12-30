class MyCircularQueue {

private:

    vector<int> data;   // underlying array to store elements
    int front;          // index of FIRST element in queue
    int rear;           // index of LAST element in queue
    int count;          // total number of elements currently present
    int capacity;       // maximum size of queue

public:

    // Constructor — create queue of size k
    MyCircularQueue(int k) {

        data.resize(k);     // allocate memory for k items
        capacity = k;       // store capacity

        front = 0;          // front starts at 0
        rear  = -1;         // rear is -1 (queue is empty)
        count = 0;          // no elements yet
    }

    // Insert value at REAR
    bool enQueue(int value) {

        // If queue is already full → cannot insert
        if (isFull()) return false;

        // Move rear forward circularly
        rear = (rear + 1) % capacity;

        // Place value at rear position
        data[rear] = value;

        // Increase element count
        count++;

        return true;
    }

    // Delete value from FRONT
    bool deQueue() {

        // If queue empty → nothing to delete
        if (isEmpty()) return false;

        // Move front forward circularly
        front = (front + 1) % capacity;

        // One element removed
        count--;

        return true;
    }

    // Get FRONT element (without removing)
    int Front() {

        // If empty → no element
        if (isEmpty()) return -1;

        // front always points to current front element
        return data[front];
    }

    // Get REAR element (without removing)
    int Rear() {

        if (isEmpty()) return -1;

        return data[rear];
    }

    // Check if queue has no elements
    bool isEmpty() {
        return count == 0;
    }

    // Check if queue is full
    bool isFull() {
        return count == capacity;
    }
};
