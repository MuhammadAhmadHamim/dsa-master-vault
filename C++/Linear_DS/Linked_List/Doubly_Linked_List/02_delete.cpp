#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(NULL),next(NULL) {}
};

// Insert at front: new node becomes the new head
void insertAtFront(Node*& head, int value) {  // Note: Node*& (pass by reference!)
    Node* newNode = new Node(value);  // Create new node
    
	newNode->next = head;             // New node points to old head
    newNode->prev = NULL;             // New node has nothing in previous since it's the head
    
	if (head != NULL) { // Fixing the previous of head node
        head->prev = newNode;
    }
	
	head = newNode;                   // Update head to new node
}

// Insert at back: traverse to end, add new node
void insertAtBack(Node*& head, int value) {
    Node* newNode = new Node(value);
    
    // If list is empty, new node becomes head
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    // Traverse to last node
    Node* temp = head;
    while (temp->next != NULL) {  // iterate!
        temp = temp->next;
    }
    
    // temp is now at last node
    newNode->prev = temp; // Linking the previous of newNode to the last node(temp)
    temp->next = newNode;  // Link last node to new node
}

void insertAtPosition(Node*& head, int value, int pos) {
    // Special case: Insert at front (position 0)
    if (pos == 0) {
        insertAtFront(head, value);
        return;
    }
    
    // Traverse to node BEFORE insertion point
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {  // pos - 1 to stop one node before
        if (temp == NULL) {  // Safety check: position out of bounds
            cout << "Position out of bounds!" << endl;
            return;
        }
        temp = temp->next;
    }
    
    // Insert after temp
    Node* newNode = new Node(value);
    
	newNode->next = temp->next;  // Connect new node to rest of chain
    newNode->prev = temp;		 // Connect the previous pointer of the newNode to the previous node
    
	if (temp->next != NULL) { // Linking the previous of node present next to temp with newNode 
        temp->next->prev = newNode;
    }
	
	temp->next = newNode;        // Connect previous node to new node
}
void deleteFromStart(Node*& head){
    if(head == NULL){ //check if the list is empty
        cout<<"List is empty!"<<endl;
    	return;
	}
        
	Node*temp=head; //temporary pointer
    head=head->next; //moving the head pointer forward
        
	if(head != NULL){ // Linking with new head
		head->prev = NULL;
	}
		
	delete temp; // deleting the memory
    cout<<"Deleted successfully!"<<endl;
}
void deleteFromEnd(Node*& head){
    
	if(head == NULL){ //check if the list is empty
        cout<<"List is empty!"<<endl;
    	return;
	}
    
	if(head->next == NULL){ //Special case for list with a singular node
        delete head;
        head=NULL;
        cout << "Deleted successfully!" << endl;  // message
        return;
    }
    
    Node* temp=head; 
        
    while(temp->next != NULL){
        temp=temp->next; //moving current forward
    }
        
		temp->prev->next=NULL; //deleting the pointer 
        delete temp; // freeing the memory
        
		cout<<"Deleted successfully!"<<endl;
}

void deleteFromPosition(Node*& head  , int position){
    
	if(head == NULL){ //check if the list is empty
        cout<<"List is empty!"<<endl;
        return;
    }
    
    if(position == 0){ // Special case for list with a singular node
        deleteFromStart(head);
        return;
    }
    
    Node* temp=head;
        
	//forward traverse to desired position-1
    for(int i=0;i<position;i++){ 
            
		if(temp == NULL){ //checking whether we breached NULL or not
            cout<<"Position out of bound!"<<endl;
            return;
        }
        
        temp=temp->next; //moving the current forward
    }
    
	if(temp == NULL){ //Again check, this time to see if the current is at NULL or not
        cout<<"Position out of bound!"<<endl;
        return;
    }
    
	if(temp->prev != NULL){ // Defensive check for broken pointers
    	temp->prev->next=temp->next; // Skipping the node under consideration
	}

	if (temp->next != NULL) {
    	temp->next->prev = temp->prev; // Linking the previous pointer of the node next to current with the node present in previous
	} 
        	
	delete temp; // freeing up the memory
    cout<<"Deleted successfully!"<<endl;
}
// Print entire list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {  // Iterate through list
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    Node* head = NULL;
    
    // Build test list: 10 -> 20 -> 30 -> 40 -> NULL
    insertAtBack(head, 10);
    insertAtBack(head, 20);
    insertAtBack(head, 30);
    insertAtBack(head, 40);
    
    cout << "Initial list: ";
    printList(head);

    int choice;
    cout << "Which type of Deletion do you want?" << endl;
    cout << "1. Deletion at the beginning of the list" << endl;
    cout << "2. Deletion at the end of the list" << endl;
    cout << "3. Deletion at a specific point of the list" << endl;
    cout<< "Enter your choice:";
	cin >> choice;
    
    // Access list based on choice
    switch(choice) {
        
        case 1:
            deleteFromStart(head);
        break;

        case 2:
            deleteFromEnd(head);
        break;

        case 3:{
            int pos;
            cout<<"Enter the position you want to delete:";
            cin>>pos;
            deleteFromPosition(head , pos);
        break;
        }

        default:
            cout<<"Invalid Input!"<<endl;
    }
    printList(head);

    // Cleanup remaining nodes
    while(head != NULL){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
