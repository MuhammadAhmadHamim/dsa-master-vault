/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.
If this is impossible, return -1.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
    
        queue<pair<int, int>> rotten;
        int fresh = 0;
        int minutes = 0;
    
        // Find all rotten oranges and count fresh
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                    
                if(grid[i][j] == 2){
                    rotten.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
    
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            
        // BFS - process level by level
        while(!rotten.empty() && fresh > 0){
    
            minutes++;
            int size = rotten.size();
    
            // Process ALL oranges that rotted this minute
            for(int i = 0; i < size; i++){

                auto [row, column] = rotten.front();
                rotten.pop();
    
                // Check all 4 neighbors
                for(auto[dr, dc] : directions){
                        
                    int newRow = row + dr;
                    int newColumn = column + dc;
    
                    // If valid AND fresh orange
                    if(newRow >= 0 && newRow < m && newColumn >= 0 && newColumn < n && grid[newRow][newColumn] == 1){
    
                        grid[newRow][newColumn] = 2;
                        fresh--;
                        rotten.push({newRow, newColumn});
                    }
                }
            }
        }
    
        if(fresh > 0) return -1;      // Still fresh oranges = IMPOSSIBLE
        else return minutes;            // All rotted = return time
    }
};
