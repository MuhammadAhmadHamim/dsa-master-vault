#include<iostream>
#include<vector>
using namespace std;
struct Node{
	
	int data;
	string key;
	Node* next;
	
	Node(string keyValue, int val): key(keyValue), data(val), next(NULL){}
};

const int size = 17;
vector<Node*> buckets(size, NULL);

int hash(string key){
	int p = 37;
	int hashVal = 0;
	for(char c : key){
		hashVal =((hashVal * p) + int(c)) % size;
	}
	return hashVal;	
}

void put(string key, int value){
	
	int index = hash(key);
	
	if(buckets[index] == NULL){
		buckets[index] = new Node(key,value);
		return;
	}
	Node* dummy = buckets[index]; 
	while(dummy != NULL){
		if(dummy->key == key){
			dummy->data = value;
			return;
		}
		
		dummy = dummy->next;
	}
	
	Node* newNode = new Node(key,value);
	newNode->next = buckets[index];
	buckets[index] = newNode;
}
int get(string key){
	
	int index = hash(key);
	
	if(buckets[index] == NULL){
		cout<<"Bucket is empty!\n";
		return -1;
	}
	
	Node* dummy = buckets[index];
	while(dummy != NULL){
		if(dummy->key == key){
			return dummy->data;
		}
		
		dummy = dummy->next;
	} 
	
	cout<<"Key not found!\n";
	return -1;
}

void remove(string key){
	
	int index = hash(key);
	
	if(buckets[index] == NULL){
		cout<<"Bucket is empty!\n";
		return;
	}
	
	Node* prev = NULL;
	Node* current = buckets[index];
	while(current != NULL){
		if(current->key == key){
			break;
		}
		
		prev = current;
		current = current->next;
	}
	
	if(current == NULL){
		cout<<"Key not found!\n";
		return;
	}
	
	if(prev == NULL){
    	buckets[index] = current->next;
	}
	else{
		prev->next = current->next;
	}
	
	delete current;
	cout<<"Successfully deleted!\n";
}

void resize(int newSize){
	buckets.resize(newSize, NULL);
	cout<<"Resized to the given size "<<newSize<<endl;
}

void display(){
    cout << "\n=== Hash Map Contents ===" << endl;
    bool isEmpty = true;
    
    for(int i = 0; i < size; i++){
        if(buckets[i] != NULL){
            isEmpty = false;
            cout << "Bucket " << i << ": ";
            Node* current = buckets[i];
            while(current != NULL){
                cout << "(" << current->key << ", " << current->data << ")";
                if(current->next != NULL){
					cout << " -> ";
				} 
                current = current->next;
            }
            cout << endl;
        }
    }
    
    if(isEmpty){
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
