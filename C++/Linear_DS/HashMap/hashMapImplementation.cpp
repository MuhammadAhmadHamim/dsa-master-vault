#include<iostream>
#include<vector>
using namespace std;
struct Node{
	
	//Declaring the attributes(key is added to store for each value)
	int data;
	string key;
	Node* next;
	
	//Constructor for easy initialization
	Node(string keyValue, int val): key(keyValue), data(val), next(NULL){}
};

int size = 17; // Size is non-const for rehashing afterwards
vector<Node*> buckets(size, NULL); // Making an array wrapped in vector

int hash(string key){
	int p = 37;
	int hashVal = 0;
	for(char c : key){
		hashVal =((hashVal * p) + int(c)) % size; // Modulo based index-formation
	}
	return hashVal;	
}

void put(string key, int value){
	
	int index = hash(key); // converting key into index
	
	if(buckets[index] == NULL){ // Safety check if head == NULL
		buckets[index] = new Node(key,value);
		return;
	}
	Node* dummy = buckets[index]; //dummy for traversal
	while(dummy != NULL){
		if(dummy->key == key){// Checking if we found the key, if yes then we update rather than adding 
			dummy->data = value;
			return;
		}
		
		dummy = dummy->next;
	}
	
	Node* newNode = new Node(key,value);
	newNode->next = buckets[index]; // Connecting the newNode at the head of the LL at index
	buckets[index] = newNode; // Updating the pointer 
}
int get(string key){
	
	int index = hash(key); // Making the index of key
	
	if(buckets[index] == NULL){ // Safety check if it's NULL
		cout<<"Bucket is empty!\n";
		return -1;
	}
	
	Node* dummy = buckets[index];
	while(dummy != NULL){ // Traversal
		if(dummy->key == key){ //Getting the data(value) if key is found
			return dummy->data;
		}
		
		dummy = dummy->next;
	} 
	
	cout<<"Key not found!\n";
	return -1;
}

void remove(string key){
	
	int index = hash(key); // Making the index
	
	if(buckets[index] == NULL){ // Safety check if it's NULL or not
		cout<<"Bucket is empty!\n";
		return;
	}
	
	// Two-ppinter iteration/traversal
	Node* prev = NULL;
	Node* current = buckets[index];
	while(current != NULL){
		if(current->key == key){ // if key is found
			break;
		}
		
		prev = current; // Getting the record of previous pointer
		current = current->next; // Moving current forward
	}
	
	if(current == NULL){ // if traversed fully without the key being found
		cout<<"Key not found!\n";
		return;
	}
	
	if(prev == NULL){ // if key is at head(first node)
    	buckets[index] = current->next;
	}
	else{ // Linking the previous node with the node, next to the one containing key
		prev->next = current->next;
	}
	
	delete current; // deleteing the node containing key
	cout<<"Successfully deleted!\n";
}

void rehash(int newSize){

	vector<Node*> oldBuckets = buckets; // saving the old map

    buckets.clear(); // clear it
    buckets.resize(newSize, NULL); // change the size and fill all the nodes with NULL

    int oldSize = size; // IMPORTANT: you should make size non-const for real system

    size = newSize; // Updating the size to new one

    for(int i = 0; i < oldSize; i++){ // Iteration through the old size

        Node* current = oldBuckets[i]; // Dummy for iteration

        while(current != NULL){ // Until we get to the ned

            Node* nextNode = current->next; // Saving the nextNode

            int index = hash(current->key); // Making the index for this node's key

            // insert into new table (reuse logic)
            current->next = buckets[index]; // linking this node with the head(first node of bucket)
            buckets[index] = current; // Updating the pointer to the newNode(making it head node)

            current = nextNode; // Restoring the nextNode we saved 
        }
    }

    cout << "Rehashing done to size " << newSize << endl;
}

void display(){
    cout << "\n=== Hash Map Contents ===" << endl;
    bool isEmpty = true;
    
    for(int i = 0; i < size; i++){ // Iteration until the size
        if(buckets[i] != NULL){ // if even one is found NOT NULL
            isEmpty = false; // change isEmpty
            cout << "Bucket " << i << ": ";
            Node* current = buckets[i]; // dummy for traversal
            while(current != NULL){ // Until it's NULL
                cout << "(" << current->key << ", " << current->data << ")"; // printing the key and value
                if(current->next != NULL){
					cout << " -> ";
				} 
                current = current->next; // Moving current forward
            }
            cout << endl;
        }
    }
    
    if(isEmpty){ // If all the buckets are empty
        cout << "Hash map is empty!" << endl;
    }
    cout << endl;
}

int main(){
	
	int choice;
    string key;
    int value;
    
    while(true){
    	cout << "\n=== Hash Map Menu ===" << endl;
        cout << "1. Put (Insert/Update)" << endl;
        cout << "2. Get (Retrieve)" << endl;
        cout << "3. Remove (Delete)" << endl;
        cout << "4. Display All" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if(choice == 5){
            cout << "Exiting..." << endl;
            break;
        }
        
        switch(choice){
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                put(key, value);
                break;
            
            case 2:
                cout << "Enter key: ";
                cin >> key;
                value = get(key);
                if(value != -1){
                    cout << key << " = " << value << endl;
                }
                break;
            
            case 3:
                cout << "Enter key: ";
                cin >> key;
                remove(key);
                break;
            
            case 4:
                display();
                break;
            
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    
	return 0;
}
