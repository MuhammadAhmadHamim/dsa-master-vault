// Given the root of a binary tree, invert the tree, and return its root.
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
            
        swapping(root); // Calling the swapping function while passing the root, by reference 
    
    return root;
    }
    
    void swapping(TreeNode* root){
    
        if(root == NULL) return; // Base case
    
        TreeNode* temp = root->left; // Save left
        root->left = root->right; // Swap
        root->right = temp; // Complete swap
            
        swapping(root->left); // Recurse left
        swapping(root->right); // Recurse right
    }
};
