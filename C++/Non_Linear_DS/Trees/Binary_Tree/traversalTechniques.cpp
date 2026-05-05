#include<iostream>
using namespace std;
struct TreeNode{
	
	int data;
	TreeNode* left;
	TreeNode* right;
	
	// Constructor for easy initialization
	TreeNode(int val): data(val), left(NULL), right(NULL){}
};

void preOrder(TreeNode* root){
	
	if(root == NULL) return; // return case
	
	cout<<root->data<<" "; // Root
	preOrder(root->left); // Left
	preOrder(root->right); // Right	
}

void inOrder(TreeNode* root){
	
	if(root == NULL) return;
	
	inOrder(root->left); // Left
	cout<<root->data<<" "; // Root
	inOrder(root->right); // Right	
}

void postOrder(TreeNode* root){
	
	if(root == NULL) return;
	
	postOrder(root->left); // Left 
	postOrder(root->right); // Right
	cout<<root->data<<" "; // Root
}

int main(){
	
	// Sample tree 
    /*
            10
           /  \
          5    15
         / \     
        3   7    
    */
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    int choice;

    while(true){
        cout << "\n===== TREE TRAVERSAL MENU =====\n";
        cout << "1. Preorder Traversal\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 4){
            cout << "Exiting...\n";
            break;
        }

        cout << "Traversal: ";

        switch(choice){
            case 1:{
				preOrder(root);
				break;
			}

            case 2:{
				inOrder(root);
				break;
			}

            case 3:{
            	postOrder(root);
				break;
			}

            default:
                cout << "Invalid choice!";
        }

        cout << endl;
    }
	
	return 0;
}
