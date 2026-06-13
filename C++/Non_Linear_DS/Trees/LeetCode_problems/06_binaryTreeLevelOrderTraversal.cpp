/*
Given the root of a binary tree, return the level order traversal of its nodes' values.
(i.e., from left to right, level by level).
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results; // Vector of vectors holding each row
        BFS(root,results); // Call the BFS function
        return results; 
    }

    void BFS(TreeNode* root, vector<vector<int>>& results){ // Passing root and results(by reference)
        if(root == NULL) return; // Base case
    
        queue <TreeNode*> container; // Initializing a queue
        container.push(root); // Pushin root of the tree inside queue
            
        while(!container.empty()){ // Until Queue is empty
                
            int levelSize = container.size(); // Saving the level
            vector<int> row; // Vector for each row
    
            for(int i = 0 ; i < levelSize; i++){
    
                TreeNode* current = container.front(); // Saving the node at front
                container.pop(); // Poppin it out
                row.push_back(current->val); // Pushing the value inside queue
    
                if(current->left != NULL){ // If the current node has some node at its left, then push it in queue
                    container.push(current->left);
                }
                
                if(current->right != NULL){ // If the current node has some node at its left, then push it in queue
                    container.push(current->right);
                }
                
            }
    
            if(!row.empty()){ // If the row has some values, then put them in results
                results.push_back(row);
            }
        }
    }   
};
