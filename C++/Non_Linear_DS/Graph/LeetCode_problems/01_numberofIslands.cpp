/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfsHelper(vector<vector<char>>& grid, int i, int j, int m, int n){
        
        // Boundary check + water check
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0'){
            return;
        }
    
        // Mark as visited (convert to water)
        grid[i][j] = '0';
    
        // Explore all 4 directions
        dfsHelper(grid, i + 1, j, m, n);  // Down
        dfsHelper(grid, i - 1, j, m, n);  // Up
        dfsHelper(grid, i, j + 1, m, n);  // Right
        dfsHelper(grid, i, j - 1, m, n);  // Left
    }
    
    int numIslands(auto& grid) {
        
        // Edge case: empty grid
        if(grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
    
        // Check ENTIRE grid (including last row and column)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){    
    
                if(grid[i][j] == '1'){
                    count++;
                    dfsHelper(grid, i, j, m, n);
                }
            }
        }
    
        return count;
    }
};
