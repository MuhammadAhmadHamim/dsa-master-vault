#include<iostream>
using namespace std;
struct TreeNode{ // Defining a tree node with two pointers 
	
	int data;
	TreeNode* left; // left pointer for left-subtree
	TreeNode* right; // right pointer for right-subtree
	
	// Constructor for easy initialization
	TreeNode(int val): data(val), left(NULL), right(NULL){}
};

int findMin(TreeNode* root){ // Function to find the minimum value from a tree
    
	if(root == NULL){ // If tree is empty
        return -1; 
    }

    // Iterate until the left pointer of the node under study is empty(no smaller values)
	while(root->left != NULL){ 
        root = root->left;
    }
    
    return root->data; // Return the data(value) of the smallest value'd node
}

int findMax(TreeNode* root){ // Function to find the maximum value from a tree
    
	if(root == NULL) return -1; // If tree is empty
    
	// Iterate until the right pointer of the node under study is empty(no greater values)
	while(root->right != NULL){
        root = root->right;
    }
    
	return root->data; // Return the data(value) of the largest value'd node
}

void insert(TreeNode*& root, int value){
	
	if(root == NULL){ // If tree is empty OR we reach the leaf node's pointer(left or right) 
		root = new TreeNode(value);
		return;
	}
	
	if(value < root->data){ // If value is less than root value, we recurse in the left direction
		insert(root->left, value);
	}
	else if(value > root->data){ // If value is greater than root value, we recurse in the right direction
		insert(root->right, value);
	}
}

void search(TreeNode*& root, int value){
	
	if(root == NULL){ // If tree is empty, or value not found after recursion through a whole tree
		cout<<"Not found!\n";
		return;
	}
	
	if(root->data == value){ // If found
		cout<<"Found!\n";
		return;
	}
	
	if(value < root->data){ // Value less than root value, search left
		search(root->left, value);
	}
	else if(value > root->data){ // value greater than root value, search right
		search(root->right, value);
	}
}

bool remove(TreeNode*& root, int value){ // Remove since delete is a reserved keyword in Cpp
	
	if(root == NULL){ // If tree is empty(Base case) 
		return false;
	}
	
	if(value < root->data){ // If value is less than root value, remove from left side
		remove(root->left, value);
	}
	else if(value > root->data){ // If value is greater than root value, remove from right side
		remove(root->right, value);
	}
	else{ // If found
			
		// The first two conditions can both be used for leaf node case since the root becomes NULL 
		// because both left and right are NULL for leaf node
		if(root->left == NULL){ // If there's no subtree in left side(one child case for right)
					
			TreeNode* temp = root; // Saving the node, containing the value, to be deleted
			
			root = root->right; // Move root to the right side
			
			delete temp; // delete temp
			return true;
		}
		else if(root->right == NULL){ // If there's no subtree in right side(one child case for left)
			
			TreeNode* temp = root; // Saving the node, containing the value, to be deleted
			
			root = root->left; // move root to the left side 
			
			delete temp; // delete temp
			return true;
		}
		else{ // two child case 
			int minVal = findMin(root->right); // Find the min value from right subtree
			root->data = minVal; // Update the original root data with minimum from right subtree 
			remove(root->right, minVal); // remove the minimum value node from right subtree
		
		// Why minimum from right subtree?
		// Because after updating the value to be deleted, we need to maintain the structural integrity of BST
		// So, we have to find some value from BST which can fill in the void.
		// A value which is less then greater root->left but close to the value of original root data.
		// So we go to the right subtree but towards it's lowest value 
		// since it's be very close to the original root's data 
		}
	}	
}

int main(){
	
	TreeNode* root = NULL;

    int choice, value;

    while(true) {
        cout << "\n===== BST MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Find Min\n";
        cout << "4. Search\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 5) {
            cout << "Exiting...\n";
            break;
        }

        switch(choice) {

            case 1:{
                cout << "Enter value to insert: ";
                cin >> value;
                insert(root, value);
                cout << "Inserted!\n";
                break;
			}
			
            case 2:{
                cout << "Enter value to delete: ";
                cin >> value;
                bool isRemoved = remove(root, value);
                if(isRemoved){
                cout << "Deleted!\n";
            	}
            	else{
            		cout<<"Value not found!";
				}
                break;
			}
            
			case 3:{
                if(root == NULL) {
                    cout << "Tree is empty!\n";
                } else {
                    cout << "Minimum value: " << findMin(root) << endl;
                }
                break;
			}
            
			case 4:{
                cout << "Enter value to search: ";
                cin >> value;
                search(root, value);
                break;
			}
			
            default:
                cout << "Invalid choice!\n";
        }
    }

	return 0;
}
