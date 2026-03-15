/*
Design Circular Queue
Design your implementation of the circular queue.
The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle,
and the last position is connected back to the first position to make a circle.
It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue.
In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. 
But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.

int Front() Gets the front item from the queue. If the queue is empty, return -1.

int Rear() Gets the last item from the queue. If the queue is empty, return -1.

boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.

boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.

boolean isEmpty() Checks whether the circular queue is empty or not.

boolean isFull() Checks whether the circular queue is full or not.

You must solve the problem without using the built-in queue data structure in your programming language. 
*/
class MyCircularQueue {
    private:
        int* q; // pointer to point at the data structure
        int f; // front counter
        int r; // rear counter
        int counter;  // counter to count the total elements
        int capacity; // size of queue
    public:
        
        MyCircularQueue(int k) { //Constructor
            capacity = k; // saving the size
            q = new int[k]; // Initialization
            f = 0; // f starting at 0
            r =  -1; // r starting at -1
            counter = 0;   // no elements now
        }
        
        ~MyCircularQueue() {
        delete[] q;  // Free memory
        }
    
        bool enQueue(int value) {
            if(isFull()){return false;} //checking if it's full already
            r=(r+1) % capacity; //updating the r counter to revolve around capacity
            q[r]=value; // adding the value
            counter++; // updating the values counter
            return true;
        }
        
        bool deQueue() {
           if(isEmpty()){return false;}  //checking if it's empty already
           f=(f+1) % capacity; //updating the f counter to revolve around capacity
           counter--; // updating the values counter
            return true;
        }
        
        int Front() {
            if(isEmpty()){return -1;} //checking if it's empty
            return q[f]; // Returning the element at front
        }
        
        int Rear() {
            if(isEmpty()){return -1;} //checking if it's empty
            return q[r]; // Returning the element at rear
        }
        
        bool isEmpty() {
           return (counter == 0); // checking if the values counter is 0
        }
        
        bool isFull() {
            return (counter == capacity); // checking if the values counter is equal to size
        }
};
