#include<iostream>
using namespace std;

// Initializing all the required variables
const int capacity = 10;
int s[capacity];
int top = -1;
int count = 0;

bool isEmpty(){
	return (count == 0); // if top is untouched
}

bool isFull(){
	return (count == capacity); // If top is equal to the capacity, turned index, of stack
}

void push(int val){
	
	if(isFull()){ // Checking if it's already full
		cout<<"Stack already full!"<<endl;
		return;
	}
	
	top++; // Moving the top up
	s[top] = val; // Adding value 
	cout<<"Successfully pushed "<<val<<" into the stack!\n";
	count++; // Increasing the value count
}

void pop(){
	
	if(isEmpty()){ // Checking if it's already empty
		cout<<"Stack already empty!\n";
		return;
	}
	
	int value = s[top]; // saving the value
	top--; // Moving the top down
	cout<<"Successfully popped "<<value<<" from the Stack!";
	count--;
}

void display(){
	
	if(isEmpty()){ // Checking if it's already empty
		cout<<"Stack is empty!\n";
		return;
	}
	
	for(int i = top; i >= 0; i--){ // Starting from top and moving down
		cout<<s[i]<<" ";
	}
}

int peek(){
	if(isEmpty()){ // Checking if it's already empty
		cout<<"Stack is empty!\n";
		return -1;
	}
	return s[top];
}

int main(){
	
	int choice;
	
	cout << "\n=== Stack Menu ===" << endl;
    cout<<"1. Push"<<endl;
    cout<<"2. Pop"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Peek"<<endl;
    cout<<"Enter choice:";
    cin>>choice;
    
    switch(choice){
    	
		case 1:{
    		int value;
    		cout<<"Enter the value:";
    		cin>>value;
    		push(value);
    	break;
    	}
    	
    	case 2:
    		pop();
    	break;
    	
    	case 3:
    		display();
    	break;
    	
    	case 4:
    		cout<<peek();
    	break;
    	
    	default:
    		cout<<"Invalid choice!"<<endl;
    	break;
	}
    
	return 0;
}
