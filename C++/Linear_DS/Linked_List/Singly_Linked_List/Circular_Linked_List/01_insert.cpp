#include<iostream>
using namespace std;

struct Node {
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

// Insert at back: traverse to end, add new node
void insertAtBack(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);
    
    // If list is empty, new node becomes head
    if (head == NULL) {
        head = tail = newNode;
        newNode->next = head;
        return;
    }
    
    // tail is at last node
    newNode->next = head;  // Link new node to head
    tail->next = newNode; // Linking the whole list with the newNode
    tail = newNode; 	 // Updating the tail pointer to the newNode
}

void insertAtPosition(Node*& head, Node*& tail, int value, int pos) {
    // Special case: Insert at front (position 0)
    if (pos == 0) {
        insertAtFront(head,tail,value);
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
	
	// Special case: Insert at last
    if (temp == tail) {
        insertAtBack(head,tail,value);
        return;
    }
	
    // Insert after temp
    Node* newNode = new Node(value);
    newNode->next = temp->next;  // Connect new node to rest of chain
    temp->next = newNode;        // Connect previous node to new node
}
// Print entire list
void printList(Node*& head, Node*& tail) {
    Node* temp = head;
    do{  // Iterate through list
        cout << temp->data << " -> ";
        temp = temp->next;
    }while(temp != head);
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;  // Started with empty list
    Node* tail = NULL; 
    
    int choice;
    cout << "Which type of Insertion do you want?" << endl;
    cout << "1. Insertion at Front of the list" << endl;
    cout << "2. Insertion at the Back of the list" << endl;
    cin >> choice;
    
    // Built list based on choice
    switch(choice) {
        case 1:  // Insert at front
            insertAtFront(head, tail, 60);   // List: 60 -> head
            insertAtFront(head, tail, 20);   // List: 20 -> 60 -> head
            insertAtFront(head, tail, 80);   // List: 80 -> 20 -> 60 -> head
            break;
            
        case 2:  // Insert at back
            insertAtBack(head, tail, 60);    // List: 60 -> head
            insertAtBack(head, tail, 20);    // List: 60 -> 20 -> head
            insertAtBack(head, tail, 80);    // List: 60 -> 20 -> 80 -> head
            break;
            
        default:
            cout << "Invalid Input!" << endl;
            return 0;
    }
    
    // Print the entire list
    cout << "Linked List: ";
    printList(head, tail);
    
    // Free memory ()
    tail->next = NULL;
	while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
