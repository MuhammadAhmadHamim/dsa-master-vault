/*
Implement a first in first out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.

int pop() Removes the element from the front of the queue and returns it.

int peek() Returns the element at the front of the queue.

boolean empty() Returns true if the queue is empty, false otherwise.

Notes:

(i)  You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, 
    and is empty operations are valid.

(ii) Depending on your language, the stack may not be supported natively.
    You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
*/
class MyQueue {
    private:
        stack<int> s1; // Input stack
        stack<int> s2; // Output stack
    public:
        MyQueue() {
            //No need to initialize anything the stacks start empty
        }
        
        void push(int x) {
            
            s1.push(x); // Pushing into the s1 stack
        
        }
        
        int pop() {
            
            if(s2.empty()){ // If s2 has no elements
                
                transfer();
            
            }
            
            int top = s2.top(); // Saving the element on top of s2
            s2.pop(); // Removing it 
            
            return top; // Returning the saved element
        }
        
        int peek() {
            if(s2.empty()){ // If s2 has no element
                transfer();
        }
            return s2.top(); // Returning the element on top
        }
        
        bool empty() {
            
            return s1.empty() && s2.empty(); // Checking if both stacks are empty or not
        
        }

        void transfer() {
            
            while(!s1.empty()){ // Using a loop to transfer from s1
                s2.push(s1.top()); //Pushing from the top of s1 into s2 (reversing the order)
                s1.pop(); //Removing the element which is added in s2 from s1
            }

        }
};
