// //Leetcode:20. Valid Parentheses

// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"

// Output: true

// Example 2:

// Input: s = "()[]{}"

// Output: true

// Example 3:

// Input: s = "(]"

// Output: false

// Example 4:

// Input: s = "([])"

// Output: true

// Example 5:

// Input: s = "([)]"

// Output: false

 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n =s.length();
        for(char & ch: s)
        {
            if(st.empty() ||ch=='(' || ch =='{' || ch =='[')
            {
                st.push(ch);
                continue;
            }
            if(ch==')')
            {
                if(st.top()=='(')
                {
                    st.pop();
                    continue;
                }
                else{
                return false;
                }
            }
           else if(ch=='}')
            {
                if(st.top()=='{')
                {
                    st.pop();
                    continue;
                }
                              else{
                return false;
                }
            }
           else  if(ch==']')
            {
                if(st.top()=='[')
                {
                    st.pop();
                    continue;
                }
                               else{
                return false;
                }
            }
        }
        return st.empty();
            }
};