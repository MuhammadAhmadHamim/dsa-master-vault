/*
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

You can return the answer in any order.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // Declaring our HashMap
        
        for(int i = 0; i < nums.size(); i++){ // Iterating over the input Array 
            int comp = target - nums[i]; // Saving the complement by subtracting element of array from target
                
            if(seen.count(comp)){ // using .count() function of Hash_Map to check whether the comp exists in hash_map or not
                return {seen[comp], i}; // If exists, we return the index of comp and index of element of array being checked 
            }
    
            seen[nums[i]] = i; // Saving the index of element of array if it's not generating the required complement
        }
    return {}; // Safety case(extra since the question ensures that there must be a solution)
    }
};
    /*
    0
    ms
    Beats
    100.00%
    
    14.93
    MB
    Beats
    18.41%
    */