/*
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.

boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.

boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.

boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.

boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.

int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.

int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.

boolean isEmpty() Returns true if the deque is empty, or false otherwise.

boolean isFull() Returns true if the deque is full, or false otherwise.
*/
class MyCircularDeque {
    private:
        int size;
        int* q;
        int f;
        int r;
        int count;
    public:
        MyCircularDeque(int k) {
            size = k;
            q = new int[k];
            f = 0; // starting front from 0
            r = k - 1; // starting rear from last
            count = 0; 
        }
        
        bool insertFront(int value) {
            // Check if full
            if(isFull()){
                return false;
            }

            // front moves backward and wraps itself around the size of q
            f = (f - 1 + size) % size;
            q[f]= value;
            count++; // Increasing the counting of variable
            return true;
        }
        
        bool insertLast(int value) {
            // Check if full
            if(isFull()){
                return false;
            }
    
            // Increase & Wrap around
            r = (r + 1) % size;
            q[r]= value;
            count++; // Increasing the count of elements
            return true;
        }
        
        bool deleteFront() {
            // Check if empty
            if (isEmpty()){
                return false;
            }
    
            // Reciprocal of rear
            f = (f + 1) % size;
            count--;
            return true;
        }
        
        bool deleteLast() {
            // Check if empty
            if (isEmpty()){
                return false;
            }
    
            // Decrease and wrap around(size is added to prevent negative index values)
            r = (r - 1 + size) % size;
            count--; // Decreasing the element count
            return true; 
        }
        
        int getFront() {
            // Check if empty
            if (isEmpty()){
                return -1;
            }
            return q[f];
        }
        
        int getRear() {
            // Check if empty
            if (isEmpty()){
                return -1;
            }
            return q[r]; 
        }
        
        bool isEmpty() {
            return (count == 0);
        }
        
        bool isFull() {
            return (count == size);
        }
    };