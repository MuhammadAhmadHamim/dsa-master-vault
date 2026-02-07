package Java.Linear_DS;
/*
Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same.
Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
The first k elements of nums should contain the unique numbers in sorted order. 
The remaining elements beyond index k - 1 can be ignored. 
*/
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        
        int i = 0; // The "Unique" pointer
        
        for (int j = 1; j < nums.length; j++) {
            // If the current number is different from the last unique number
            if (nums[j] != nums[i]) {
                i++;           // Move the unique pointer forward
                nums[i] = nums[j]; // Update the original array in-place
            }
        }
        
        // Return i + 1 because i is an index (0-based)
        return i + 1; 
    }
}