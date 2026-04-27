/*
Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups; // Initializing our own HashMap (sorted string -> anagram)
        for(string s : strs){ // Iterating through the strings given 
            string key = s; // We copy the string into key and then sorted the copy
            
            sort(key.begin(), key.end()); // Sort function taking starting point and ending point as arguments
            //It arranges the characters in lexicographical order


            groups[key].push_back(s); // Pushing the original string into the groups hashMap in the bucket = sorted key 
        }
        
        vector<vector<string>> result; // Initializing the vector string for results
        for(auto& pair : groups){ // Using auto to auto-detect the dataType and iterate through the hashMap
            result.push_back(pair.second); //  Taking the second element of pair(vector of strings) and pushing it into result
        }
        return result; // Returning the result
    }
};