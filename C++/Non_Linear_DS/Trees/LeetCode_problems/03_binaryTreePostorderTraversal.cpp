/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.
*/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result; // Initializing the result vector
            
        postOrder(root, result); // Calling the postOrder method
        
    return result;
    }
    
    void postOrder(TreeNode* root, vector<int>& result){
        
        if(root == NULL) return; // If NULL, go back
        
        postOrder(root->left, result); // Left
        postOrder(root->right, result); // Right
        result.push_back(root->val); // Root
    }
};
