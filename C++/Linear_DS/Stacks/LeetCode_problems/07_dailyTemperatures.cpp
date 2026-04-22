/*
Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that 
answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/
class Solution {
private:
    stack<int> st; // A stack to store indices
        
    // A vector to store difference of days(i.e. answers) 
    // with default value being zero for size equal to that of incoming temperatures
    vector<int> answers(temperatures.size(), 0); 
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
            
        for(int i = 0; i < temperatures.size(); i++){ // For iterating through the temperatures of days
    
            // Using a while loop to iterate thorough the unresolved indices of days in stack 
            // as soon as we get a warmer day and stack is not empty
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){ 
                
                // Fixing the value at index(st.top()) of answers
                // by saving the difference of indices of days calculated 
                // through subtracting the index of unresolved day from index of day being judged 
                answers[st.top()]= i - st.top(); 
                    
                st.pop(); // Removing the index of day who's been fixed
            }

            st.push(i); // Pushing the day being judged(getting in line to wait for day warmer than it)
        }
    return answers; 
    }
};