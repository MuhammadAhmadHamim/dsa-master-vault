/*
There are n cities. Some of them are connected, while some are not.
If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfsHelper(vector<vector<int>>& isConnected, int city, vector<bool>& visited){
        visited[city] = true;  // Mark as visited
        int m = isConnected[0].size();
    
        // Check all cities connected to current city
        for(int j = 0; j < m; j++){
                
            // If connected AND not visited
            if(isConnected[city][j] == 1 && !visited[j]){
                dfsHelper(isConnected, j, visited);  // Explore
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
    
        // Find all unvisited cities
        for(int i = 0; i < n; i++){
                
            // New province found
            if(!visited[i]){
                provinces++;
                dfsHelper(isConnected, i, visited);  // Explore entire province
            }
        }
        
        return provinces;
    }
};
