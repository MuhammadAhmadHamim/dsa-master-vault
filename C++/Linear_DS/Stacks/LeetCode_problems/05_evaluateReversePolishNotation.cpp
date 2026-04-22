/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.

Each operand may be an integer or another expression.

The division between two integers always truncates toward zero.

There will not be any division by zero.

The input represents a valid arithmetic expression in a reverse polish notation.

The answer and all the intermediate calculations can be represented in a 32-bit integer.
*/
class Solution {
private:
    stack<int> st; // Initializing a stack
public:
    bool isOperator(string s){ // Checking if it's an operator
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }
    
    int evalRPN(vector<string>& tokens) {
        for(string s : tokens){ // Going through the string one by one
            if(!isOperator(s)){ // If, not, an operator
                
                st.push(stoi(s)); // Push it after conversion into int
            }
            else{
                
                int b = st.top(); // Pop the second element
                st.pop(); // Remove it
                
                int a = st.top(); // Pop the first element
                st.pop(); // Remove it
                
                // Checking the operator and performing the operation before pushing the result back to stack
                if(s == "+") st.push(a + b); 
                else if(s == "-") st.push(a - b);
                else if(s == "*") st.push(a * b);
                else if(s == "/") st.push(a / b);
            }
        }
        return st.top(); // Returning the value at the top of stack(final result after the execution of whole loop)
    }
};