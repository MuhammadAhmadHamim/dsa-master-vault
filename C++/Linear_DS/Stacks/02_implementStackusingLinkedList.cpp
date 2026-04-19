#include<iostream>
using namespace std;

struct Node { // Defining the structure of a node 
	
	int data;
	Node* next;
	
	Node(int val): data(val), next(NULL) {}
};
Node* head = NULL; // Defining the top of our stack

bool isEmpty(){
	return (head == NULL);	// Empty condition
}

void push(int value){
	Node* newNode = new Node(value); // Create new node
	newNode->next = head; // New node points to old head(head is a pointer which is pointing to the chain)
	head = newNode; // Update head to new node
	cout<<"Successfully pushed "<< head->data <<" into the Stack!\n";
}

void pop(){
	if(isEmpty()){ // Checking if it's already empty
		cout<<"Stack is empty!\n";
		return;
	}
	
	Node* temp = head; // Saving the node to be deleted
	head = head->next; // Moving the head forward 
	cout<<"Successfully popped "<< temp->data <<" from the Stack!\n";
	delete temp; // Deleting the previous node
}

void display(){
	
	if(isEmpty()){ // Checking if it's already empty
		cout<<"Stack is empty!\n";
		return;
	}
	
	Node* dummy = head; // Using a fake head for traversal
	
	cout<<"Stack(top to bottom):"<<endl;
	while(dummy != NULL){
		cout<<dummy->data<<endl; // Printing the data in the node to which dummy is pointing 
		dummy = dummy->next; // Moving the dummy forward
	}
}

int peek(){
	
	if(isEmpty()){ // Checking if it's already empty
		cout<<"Stack is empty!\n";
		return -1;
	}
	
	return head->data; // Returning the data stored in the node being pointed by head
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
