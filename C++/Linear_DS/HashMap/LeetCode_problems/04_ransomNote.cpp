/*
Given two strings ransomNote and magazine,
return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> available; // Declaring our HashMap(character -> frequency)
        
        for(char c : magazine) available[c]++; // Counting all the characters available in magazine

        for(char c : ransomNote){ // Iterating through ransomNote 
            
            // If any character's frequency is less than or equal to zero,
            //  then it's absent and so ransomNote can't be constructed from magazine
            if(available[c] <= 0) return false; 
            
            available[c]--; // Counting down the character if it's present 
        } 
    return true; // If all the characters are present 
    }
};