/*
You are keeping the scores for a baseball game with strange rules.
At the beginning of the game, you start with an empty record.

You are given a list of strings operations,
where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x.
Record a new score of x.

'+'.
Record a new score that is the sum of the previous two scores.

'D'.
Record a new score that is the double of the previous score.

'C'.
Invalidate the previous score, removing it from the record.

Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer
and that all operations are valid.
*/
class Solution {
private:
    stack<int> st; // Initializing a stack for storing values
public:
    int calPoints(vector<string>& operations) {
        for(string s: operations){
            if(s == "+"){ // if +
                
                int b = st.top(); // Saving the last score
                st.pop(); // Removing it
                
                int a = st.top(); // Saving the second-last
                st.push(b); // Pushing the last back to avoid data loss
                
                st.push(a + b); // Pushing the result
            }
            else if(s == "D") st.push(st.top() * 2); // Doubling the previous score and saving the result
            else if(s == "C") st.pop(); // Removing the last score
            else{
                st.push(stoi(s)); // If no operator then integer, pushed into stack after conversion into integer dataType
            }
        }
        int sum = 0; 
        
        while(!st.empty()){ // Until stack is empty
            sum += st.top(); // Updating the sum
            st.pop(); // Removing the element which has been added
        }

    return sum;
    }
};