/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result; // Initializing the result vector
        
        preOrder(root, result); // Calling the preOrder method
        
    return result;
    }
        
    void preOrder(TreeNode* root, vector<int>& result){
    
        if(root == NULL) return; // If NULL, go back
    
        result.push_back(root->val); // Root
        preOrder(root->left, result); // Left
        preOrder(root->right, result); // Right
    }
};
