#include<iostream>
#include<queue>
using namespace std;

struct TreeNode{
	
	int data;
	TreeNode* right;
	TreeNode* left;
	
	TreeNode(int val): data(val), right(NULL), left(NULL) {}
	
};

// Insertion using Recursion
void insert(TreeNode*& root, int val){
	
	if(root == NULL){
		root = new TreeNode(val);
		return;
	}
	
	if(root->data > val)
		insert(root->left, val);
	
	else if(root->data < val)
		insert(root->right, val);
}

void BFS(TreeNode* root){
	
	if(root == NULL) return;  // Handle empty tree
	
    queue<TreeNode*> container;  // Queue of node pointers
    
    container.push(root);  // Start with root
    
    while(!container.empty()){  // Process until empty
        
        TreeNode* current = container.front();  // Get front
        container.pop();  // Remove it
        
        cout<<current->data<<" ";  // Process it
        
        if(current->left != NULL)   // Add left child
            container.push(current->left);
        
        if(current->right != NULL)  // Add right child
            container.push(current->right);
    }
}

int main(){
	
	TreeNode* root = NULL;

    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);

    BFS(root);
	
	return 0;
}
