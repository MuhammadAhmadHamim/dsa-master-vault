#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(NULL),next(NULL) {}
};

// Insert at front: new node becomes the new head
void insertAtFront(Node*& head, Node*& tail, int value) {  // Note: Node*& (pass by reference!)
    Node* newNode = new Node(value);  // Create new node
    
    // If list is empty, new node becomes head
    if (head == NULL) {
        head = tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
    
	newNode->next = head;             // New node points to old head
    newNode->prev = tail;             // New node has to connect with the tail
    
	if (head != NULL) { 			  // Fixing the previous of head node
        head->prev = newNode;
    }
	
	head = newNode;                   // Update head to new node
	tail->next = head; 				// Tail must point to the new head
}

// Insert at back: traverse to end, add new node
void insertAtBack(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);
    
    // If list is empty, new node becomes head
    if (head == NULL) {
        head = tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
    
    // temp is now at last node
    newNode->prev = tail; // Linking the previous of newNode to the last node(tail)
    tail->next = newNode;  // Link last node to new node
    tail = newNode;			// NewNode becomes the tail
    tail->next = head;  // Linking newNode next to the head to maintain circularity from tail side
    head->prev = tail; 	// head must point to the new tail to maintain circularity from head side
}

void insertAtPosition(Node*& head, Node*& tail, int value, int pos) {
    // Special case: Insert at front (position 0)
    if (pos == 0) {
        insertAtFront(head, tail, value);
        return;
    }
	
	Node* newNode = new Node(value);
	
	// If list is empty, new node becomes head
    if (head == NULL) {
        head = tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
    
    // Traverse to node BEFORE insertion point
    Node* temp = head;
    int i = 0;
	do{	
		temp = temp->next; // moving temp forward
		
		if(temp == head){ // Safety check for bounderies
        	cout<<"Index out of bounds!\n";
        	return;
		}
		
        i++; // counting steps
        
    }while(i < pos -1);
    
    // Special check for temp reaching tail
     if(temp == tail){
    	insertAtBack(head, tail, value);
        return;
	}
    
    // Insertion after temp
    
	newNode->next = temp->next;  // Connect new node to rest of chain
    newNode->prev = temp;		 // Connect the previous pointer of the newNode to the previous node
	temp->next->prev = newNode;		// Linking the previous of node present next to temp with newNode 
	temp->next = newNode;        // Connect previous node to new node
}

// Print entire list
void printList(Node* head) {
    Node* temp = head;
    do{  // Iterate through list
        cout << temp->data << " -> ";
        temp = temp->next;
    }while (temp != head);
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;  // Started with empty list
    Node* tail = NULL;
    
    int choice;
    cout << "Which type of Insertion do you want?" << endl;
    cout << "1. Insertion at Front of the list" << endl;
    cout << "2. Insertion at the Back of the list" << endl;
    cout << "3. Insertion at specific position in the list" << endl;
    cin >> choice;
    
    // Built list based on choice
    switch(choice) {
        case 1:  // Insert at front
            insertAtFront(head, tail, 100);   
            insertAtFront(head, tail, 30);   
            insertAtFront(head, tail, 60);   
            break;
            
        case 2:  // Insert at back
            insertAtBack(head, tail, 80);    
            insertAtBack(head, tail, 40);    
            insertAtBack(head, tail, 20);    
            break;
        
		case 3:{
			int value;
			int pos;
			cout<<"Enter the value:";
			cin >> value;
			cout<<"Enter the position:";
			cin >> pos;
			insertAtPosition(head, tail, value, pos);
			break;
		}
		    
        default:
            cout << "Invalid Input!" << endl;
            return 0;
    }
    
    // Print the entire list
    cout << "Doubly Linked List: ";
    printList(head);
    
    // Free memory ()
    tail->next = NULL;
    while(head != NULL){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
	return 0;
}
