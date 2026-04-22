/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.

void push(int val) pushes the element val onto the stack.

void pop() removes the element on the top of the stack.

int top() gets the top element of the stack.

int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.
*/
struct Node{ // Initializing a Node struct 
    int min_so_far; // For storing the minimum value of list until now
    int data;
    Node* next;

    Node(int val): data(val), min_so_far(val), next(NULL){}
};

class MinStack {
private:    
    Node* head; // Head of the list

public:
    MinStack() {
        head = NULL; // Initializing head
    }
    
    void push(int val) {
        Node* newNode = new Node(val); // Initializing a newNode
        
        if(head == NULL){ // If list is empty, newNode becomes head
            head = newNode; 
            return;
        }

        newNode->next = head; // Connecting newNode infront of the head
        if(newNode -> data > head-> min_so_far){ // if the data in newNode is greater than min, min_so_far doesn't change
            newNode->min_so_far = head-> min_so_far;
        }
        head = newNode; // Newnode becomes head    
    }
    
    void pop() {
        
        if(head == NULL){ // Safety check
            cout<<"List is empty!\n";
            return;
        }
        
        Node* temp = head; // Storing previous head
        head = head->next; // moving head forward
        delete temp; // deleting the previous head stored in temp
    }
    
    int top() {
        if(head == NULL){ // Safety check
            cout<<"List is empty!\n";
            return -1;
        }
        return head->data; // Getting the value of head->data(top of our list-turned-stack)
    }
    
    int getMin() {
        if(head == NULL){ // Safety check
            cout<<"List is empty!\n";
            return -1;
        }
        return head->min_so_far; // Getting the minimum so far
    }
};