/*
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, 
either horizontally or vertically) and shares the same color as the starting pixel.

Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.

The process stops when there are no more adjacent pixels of the original color to update.

Return the modified image after performing the flood fill.
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // DFS helper - fills all connected cells with same original color
    void dfsHelper(vector<vector<int>>& image, int sr, int sc, int m, int n, int originalColor, int newColor){
            
        // Boundary check OR color check 
        if(sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != originalColor){
            return;
        }
    
        // Change to new color
        image[sr][sc] = newColor;
    
        // Explore 4 directions
        dfsHelper(image, sr + 1, sc, m, n, originalColor, newColor);  // Down
        dfsHelper(image, sr - 1, sc, m, n, originalColor, newColor);  // Up
        dfsHelper(image, sr, sc + 1, m, n, originalColor, newColor);  // Right
        dfsHelper(image, sr, sc - 1, m, n, originalColor, newColor);  // Left
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
            
        // Get original color of starting cell
        int originalColor = image[sr][sc];
            
        // Only fill if original and new colors are different
        if(originalColor != color){
            dfsHelper(image, sr, sc, m, n, originalColor, color);
        }
    
        return image;
    }
};
