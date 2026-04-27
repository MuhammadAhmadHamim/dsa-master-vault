/*
Given an integer array nums, return true if any value appears at least twice in the array,
and return false if every element is distinct.
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> seen; // Declaration of our HashMap (value -> index)
        
        for(int i = 0; i < nums.size(); i++){ // Iterating over the input Array
            
            if(seen.count(nums[i])){ // If number is already present in HashMap(using number as key), return true
                return true;
            }
            
            seen[nums[i]] = i; // Saving the number for future checks
        }
    return false; // If loop discloses without finding any duplicate 
    }
};