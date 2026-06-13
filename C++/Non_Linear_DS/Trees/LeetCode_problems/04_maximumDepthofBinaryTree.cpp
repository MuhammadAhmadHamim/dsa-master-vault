/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode* root) {
        
        if(root == NULL) return 0; // Base case
    
        int leftdepth = maxDepth(root->left); // For calculating the depth from left side

        int rightdepth = maxDepth(root->right); // For calculating the depth from right side
    
    return 1 + max(leftdepth, rightdepth); // 1(to count root node) + maximum depth from left or right side
    }
};