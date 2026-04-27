/*
Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // Declaring our hashMap (value -> frequency)
        for(int num : nums) freq[num]++; // Counting the frequency of each element
    
        vector<pair<int, int>> freqPairs;  // {count, number}
        for(auto& p : freq){ // Going through each pair and pushing its flipped form into the vector for sorting 
            freqPairs.push_back({p.second, p.first});
        }
            
        sort(freqPairs.rbegin(), freqPairs.rend());  // Descending because first is count
    
        vector<int> result; // Using the result vector
        for(int i = 0; i < k; i++){ // Iterating through the frequency pair vector only to get k elements in result
            result.push_back(freqPairs[i].second); // Only pushing the value, not the count
        }
    return result; // returning the result
    } 
};
