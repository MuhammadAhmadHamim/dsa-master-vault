#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};
void insertAtEnd(Node*& head, int value) {
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
void deleteFromStart(Node*& head){
    if(head == NULL){ //check if the list is empty
        cout<<"List is empty!"<<endl;
    }
    else{
        Node*temp=head; //temporary pointer
        head=head->next; //moving the head pointer forward
        delete temp; // deleting the memory
        cout<<"Deleted successfully!"<<endl;
    }
}
void deleteFromEnd(Node*& head){
    if(head == NULL){ //check if the list is empty
        cout<<"List is empty!"<<endl;
    }
    else if(head->next == NULL){ //Special case for list with a singular node
        delete head;
        head=NULL;
        cout << "Deleted successfully!" << endl;  // message
    }
    else{
        Node* current=head; 
        Node* previous=NULL;
        while(current->next != NULL){
            previous=current;  //updating the value of previous
            current=current->next; //moving current forward
        }
        previous->next=NULL; //deleting the pointer 
        delete current; // freeing the memory
        cout<<"Deleted successfully!"<<endl;
    }
}
void deleteFromPosition(Node*& head  , int position){
    if(head == NULL){ //check if the list is empty
        cout<<"List is empty!"<<endl;
    }
    else if(position == 0){ // Special case for list with a singular node
        deleteFromStart(head);
    }
    else{
        Node* current=head;
        Node* previous=NULL;
        //forward traverse to desired position-1
        for(int i=0;i<position;i++){ 
            if(current == NULL){ //checking whether we breached NULL or not
                cout<<"Position out of bound!"<<endl;
                return;
            }
            else{
            previous=current; //updating the previous pointer
            current=current->next; //moving the current forward
            }
    }
        if(current == NULL){ //Again check, this time to see if the current is at NULL or not
            cout<<"Position out of bound!"<<endl;
        }
        else{
            previous->next=current->next; // Skipping the node under consideration
            delete current; // freeing up the memory
            cout<<"Deleted successfully!"<<endl;
        }
    }
}
void printList(Node*& head){
    Node* temp=head;
    while(temp != NULL){ //printing the list
        cout<<temp->data<<" -> ";
        temp=temp->next; //moving temp forward
    }
    cout<<"NULL"<<endl;
}
int main(){
    Node* head = NULL;
    
    // Build test list: 10 -> 20 -> 30 -> 40 -> NULL
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    
    cout << "Initial list: ";
    printList(head);

    int choice;
    cout << "Which type of Deletion do you want?" << endl;
    cout << "1. Deletion at the beginning of the list" << endl;
    cout << "2. Deletion at the end of the list" << endl;
    cout << "3. Deletion at a specific point of the list" << endl;
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