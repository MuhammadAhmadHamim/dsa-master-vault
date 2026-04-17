#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(NULL),next(NULL) {}
};

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
    
    // tail is at last node
    newNode->prev = tail; // Linking the previous of newNode to the last node(tail)
    tail->next = newNode;  // Link last node to new node
    tail = newNode;		// Tail now becomes the newNode
    tail->next = head;	// New tail now points to the head
    head->prev = tail; 	// head now points to the new Tail
}

void deleteFromStart(Node*& head, Node*& tail){
    if(head == NULL){ //check if the list is empty
        cout<<"List is empty!"<<endl;
    	return;
	}
	
	if(head == tail){ // Special case for singular node list
		head = tail = NULL;
		return;
	}
        
	Node*temp=head; //temporary pointer
    head=head->next; //moving the head pointer forward
    
	if(head != NULL){ // Linking with new head
		head->prev = tail; // new head now points to the Tail
		tail->next = head;	// tail now points to the new head
	}
	
	delete temp; // deleting the memory
    cout<<"Deleted successfully!"<<endl;
}

void deleteFromEnd(Node*& head, Node*& tail){
    
	if(head == NULL){ //check if the list is empty
        cout<<"List is empty!"<<endl;
    	return;
	}
    
	if(head == tail){ //Special case for list with a singular node
        delete head;
        head = NULL;
        tail = NULL;
        cout << "Deleted successfully!" << endl;  // message
        return;
    }
    
    Node* temp = tail;   // Saving the node to be deleted
    tail = tail->prev;  // Moving tail behind to skip the last node
    tail->next = head; // New tail point to head to maintain the circularity from tail side
    head->prev = tail; // head point to new tail to maintain the circularity from head side
    
    delete temp; // freeing the memory
    cout<<"Deleted successfully!"<<endl;
}

void deleteFromPosition(Node*& head, Node*& tail, int pos){
    
	if(head == NULL){ //check if the list is empty
        cout<<"List is empty!"<<endl;
        return;
    }
    
    if(pos == 0){ // Special case for list with a singular node
        deleteFromStart(head, tail);
        return;
    }
    
    Node* temp = head ; // Initializing a dummy head
    
    int i = 0; // for steps
    do{
    	
		temp = temp->next; // moving temp forward 
    	
		if(temp == head){ // Special check for boundery
    		cout<<"Index out of bounds!";
    		return;
		}
		
		i++; // counting the steps
	}while(i < pos);
	
	if(temp == tail){ //Again check, this time to see if the temp is at tail or not
        deleteFromEnd(head, tail);
        return;
    }
    
    temp->prev->next=temp->next; // Skipping the node under consideration
    temp->next->prev = temp->prev; // Linking the previous pointer of the node next to current with the node present in previous
        	
	delete temp; // freeing up the memory
    cout<<"Deleted successfully!"<<endl;
}

// Print entire list
void printList(Node* head) {
    
    if(head == NULL){ //check if the list is empty
        cout<<"List is empty!"<<endl;
        return;
    }
    
	Node* temp = head;
    
    do{ // Iterate through list
        cout << temp->data << " -> ";
        temp = temp->next;
    }while (temp != head);
    cout << "NULL" << endl;
}

int main(){
	Node* head = NULL;
    Node* tail = NULL;
    
    // Build test list: 10 -> 20 -> 30 -> 40 -> NULL
    insertAtBack(head, tail, 10);
    insertAtBack(head, tail, 20);
    insertAtBack(head, tail, 30);
    insertAtBack(head, tail, 40);
    
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
            deleteFromStart(head, tail);
        break;

        case 2:
            deleteFromEnd(head, tail);
        break;

        case 3:{
            int pos;
            cout<<"Enter the position you want to delete:";
            cin>>pos;
            deleteFromPosition(head, tail, pos);
        break;
        }

        default:
            cout<<"Invalid Input!"<<endl;
    }
    
    printList(head);

    // Cleanup remaining nodes
    tail->next = NULL;
	while(head != NULL){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
