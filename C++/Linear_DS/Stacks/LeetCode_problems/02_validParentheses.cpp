/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

(i)   Open brackets must be closed by the same type of brackets.
(ii)  Open brackets must be closed in the correct order.
(iii) Every close bracket has a corresponding open bracket of the same type.
*/
#include<iostream>
using namespace std;

stack<char> st; 

bool isValid(string s) {
    
    for(char c : s){
        
        if(c == '(' || c == '{' || c == '['){  // For opening bracket
            st.push(c);
        }
        else{
            // For closing bracket
            if(st.empty()){ // If the bracket is closing but there's no opening one
                return false;
            }

            //Checking if they match, popping out from the stack if they do
            if(st.top() == '(' && c == ')'){ 
                st.pop();
            }
            else if(st.top() == '{' && c == '}'){
                st.pop();
            }
            else if(st.top() == '[' && c == ']'){
                st.pop();
            }
            else{ // Returning false if there's a closing bracket but the opening bracket isn't matching it
                return false;
            } 
        }
    }

    return st.empty(); // Returns true if stack becomes empty(all brackets properly close), otherwise false
}