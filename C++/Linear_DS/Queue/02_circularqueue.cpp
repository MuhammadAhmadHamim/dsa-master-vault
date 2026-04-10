#include<iostream>
using namespace std;

const int SIZE = 10;
int q[SIZE];
int front = -1;
int rear = -1;
int count = 0;

// ENQUEUE - Add element
void enqueue(int value) {
    // Check if full
    if (isFull()) {  
        cout << "Queue Overflow! Cannot enqueue " << value << endl;
        return;
    }
    
    // First time: Initialize front
    if (front == -1) {
        front = 0;
    }
    
    rear= (rear + 1) % SIZE;           
    q[rear] = value;
	count++;  
    cout << "Enqueued: " << value << endl;
}

// DEQUEUE - Remove element
int dequeue() {
    // Check if empty
    if (isEmpty()) {  
        cout << "Queue Underflow! Queue is empty" << endl;
        return -1;
    }
    
    int value = q[front];  
    front = (front + 1) % SIZE;               
    count--;
    cout << "Dequeued: " << value << endl;
    return value;
}

// PEEK - View front element
int peek() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return q[front];
}

// IS EMPTY
bool isEmpty() {
    return (count == 0);
}

// IS FULL
bool isFull() {
    return (count == SIZE);
}

// DISPLAY - Print queue
void display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    
    cout << "Queue: ";
    int i = front;
    for (int j = 0; j < count; j++) {  // Loop count times
        cout << q[i] << " ";
        i = (i + 1) % SIZE;  // Circular increment
    }
    cout << endl;
}
int main(){
	
	int choice;
	
    cout<<"1. Enqueue"<<endl;
    cout<<"2. Dequeue"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Peek"<<endl;
    cin>>choice;
    
    switch(choice){
    	
		case 1:{
    		int value;
    		cout<<"Enter the value:";
    		cin>>value;
    		enqueue(value);
    	break;
        }
    	
        case 2:
    		dequeue();
    	break;
    	
    	case 3:
    		display();
    	break;
    	
    	case 4:
    		peek();
    	break;
    	
    	default:
    		cout<<"Invalid choice!"<<endl;
    	break;
	}
	
	return 0;
}

