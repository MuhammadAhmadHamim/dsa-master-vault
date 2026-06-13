/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result; // Initializing the result vector
            
        inOrder(root, result); // Calling the inOrder method
            
    return result;
    }
    
    void inOrder(TreeNode* root, vector<int>& result){
        
        if(root == NULL) return; // If NULL, go back
        
        inOrder(root->left, result); // Left
        result.push_back(root->val); // Root
        inOrder(root->right, result); // Right
    }
};
