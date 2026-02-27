#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Insert at front: new node becomes the new head
void insertAtFront(Node*& head, int value) {  // Note: Node*& (pass by reference!)
    Node* newNode = new Node(value);  // Create new node
    newNode->next = head;             // New node points to old head
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
    temp->next = newNode;  // Link last node to new node
}
void insertAtPosition(Node*& head, int value, int pos) {
    // Special case: Insert at front (position 0)
    if (pos == 0) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
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
    temp->next = newNode;        // Connect previous node to new node
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

int main() {
    Node* head = NULL;  // Started with empty list
    
    int choice;
    cout << "Which type of Insertion do you want?" << endl;
    cout << "1. Insertion at Front of the list" << endl;
    cout << "2. Insertion at the Back of the list" << endl;
    cin >> choice;
    
    // Built list based on choice
    switch(choice) {
        case 1:  // Insert at front
            insertAtFront(head, 60);   // List: 60 -> NULL
            insertAtFront(head, 20);   // List: 20 -> 60 -> NULL
            insertAtFront(head, 80);   // List: 80 -> 20 -> 60 -> NULL
            break;
            
        case 2:  // Insert at back
            insertAtBack(head, 60);    // List: 60 -> NULL
            insertAtBack(head, 20);    // List: 60 -> 20 -> NULL
            insertAtBack(head, 80);    // List: 60 -> 20 -> 80 -> NULL
            break;
            
        default:
            cout << "Invalid Input!" << endl;
            return 0;
    }
    
    // Print the entire list
    cout << "Linked List: ";
    printList(head);
    
    // Free memory ()
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
