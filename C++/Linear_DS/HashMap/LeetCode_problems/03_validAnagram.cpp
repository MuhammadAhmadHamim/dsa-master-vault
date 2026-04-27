/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word formed by rearranging the letters of another word, 
using all original letters exactly once.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq; // Declaring our HashMap(character -> frequency)
        
        for(char c : s) freq[c]++; // Counting the freq of each char
        
        for(char c : t) freq[c]--; // Checking how many are present in t by decreasing the frequency
        
        for(auto& pair : freq){ // Iterating through the hashMap using auto& which determines the type and references each pair
            
            if(pair.second != 0){ // If any character still has a value of frequency(second part) other than 0, return false
                return false; 
            }
        
        }        
    return true; // If all characters are cancelled by comparing both s and t then they are anagram
    }
};