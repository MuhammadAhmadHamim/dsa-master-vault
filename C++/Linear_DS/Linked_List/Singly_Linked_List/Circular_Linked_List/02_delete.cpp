#include<iostream>
using namespace std;

struct Node{
	
	int data;
	Node* next;
	
	Node(int val) : data(val), next(NULL) {}
	
};
// Insert at front: new node becomes the new head
void insertAtFront(Node*& head, Node*& tail, int value) {  // Note: Node*& (pass by reference!)
    
    Node* newNode = new Node(value);  // Create new node
    
	if(head == NULL){
    	head = tail = newNode;
    	newNode->next = head;
    	return; 
	}
	
    newNode->next = head;             // New node points to old head
    head = newNode;                   // Update head to new node
    tail->next = head;                // Returning back to head
}

void deleteFromFront(Node*& head, Node*& tail) {
	
	if(head == NULL){ // Empty check
		cout<<"Error! The list is empty!\n";
		return;
	}
	
	if(head == tail){ // one-node list
		head = tail = NULL;
		return;
	}
	
	Node* temp = head; // Making a newNode
	head = head->next; // Moving head forward
	tail->next = head; // Tail pointing to the new head
	delete temp;       // deleting the old head
	cout<<"Successfully deleted!\n";
}

void deleteFromBack(Node*& head, Node*& tail){
	
	if(head == NULL){ // Empty check
		cout<<"Error! The list is empty!\n";
		return;
	}
	
	if(head == tail){ // One-node list
		head = tail = NULL;
		return;
	}
	
	// Traverse to the second-last using a dummy pointer
	Node* dummy = head;
	while(true){
		
		if(dummy->next == tail){ // second last would always have tail in it's next
			break;
		}
		else{
			dummy = dummy->next; // moving the dummy forward
		}
	}
	Node* nodeTodelete = tail; // saving the node to be deleted
	dummy->next = head; // Skipping the node present at the tail
	tail = dummy; // Making the second last node as tail
	delete nodeTodelete; // deleting the old tail
	cout<<"Successfully deleted!\n";	
}

void deleteFromPosition(Node*& head, Node*& tail,int pos){
	
	if(head == NULL){ // Empty-check
		cout<<"Error! The list is empty!\n";
		return;
	}
	
	if (pos == 0){ // Deletion on position 1
		deleteFromFront(head, tail);
		return;
	}
	
	Node* temp = head; // Using a fake head
	
	for(int i=0; i < pos - 1 ; i++){ // Traversing to the specific position
		temp = temp->next; 
	}
	
	if(temp->next == tail){ // Checking if it's at the second last node
		deleteFromBack(head, tail);
		return;
	}
	
	Node* nodeTodelete = temp->next; // Saving the node to be deleted
	temp->next = temp->next->next; // Skipping the node to be deleted by jumping two places(->next->next)
	delete nodeTodelete; // Deleting the node to be deleted
	cout<<"Successfully deleted!\n";
}
void displayList(Node*& head){
	
	Node* dummy = head; // Making a dummy head
	do{
		cout<<dummy->data<<" -> "; // Printing the data
		dummy = dummy->next;	// Moving the dummy forward
	}while(dummy != head); // Checking until it reaches back to head
	
	cout<<"NULL\n";	
}
int main(){
	
	Node* head = NULL; // Declaring head
	Node* tail = NULL; // Declaring tail
	int choice; // DEclaring the choice variable
	
	cout << "\n===== Circular Linked List Menu =====\n";
	cout << "1. Insert at Front\n";
	cout << "2. Delete from Front\n";
    cout << "3. Delete from Back\n";
    cout << "4. Delete from Position\n";
    cout << "5. Display\n";
	cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {
        case 1:{
            int value;
			cout << "Enter value: ";
            cin >> value;
            insertAtFront(head, tail, value);
            break;
		}
        case 2:{
        	deleteFromFront(head, tail);
			break;
		}
        case 3:{
        	deleteFromBack(head, tail);
			break;
		}
        case 4:{
        	int pos;
			cout << "Enter position: ";
            cin >> pos;
            deleteFromPosition(head, tail, pos);	
			break;
		}
        case 5:{
        	displayList(head);
			break;
		}
    	default:
            cout << "Invalid choice!\n";
        }
		
	return 0;
}
