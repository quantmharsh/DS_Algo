// //Leetcode:856. Score of Parentheses
// Medium
// Topics
// premium lock icon
// Companies
// Given a balanced parentheses string s, return the score of the string.

// The score of a balanced parentheses string is based on the following rule:

// "()" has score 1.
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.
 

// Example 1:

// Input: s = "()"
// Output: 1
// Example 2:

// Input: s = "(())"
// Output: 2
// Example 3:

// Input: s = "()()"
// Output: 2
 

// Constraints:

// 2 <= s.length <= 50
// s consists of only '(' and ')'.
// s is a balanced parentheses string.
class Solution {
public:
    //Approach:Simple Intution.(Actualy not simple  observation)
    //We calculate the depthif s[i]=( 
    // if s[i]= ) then reduce depth and check if s[i-1]=(
    //then calculate ans +=  2^depth
    //at last return ans
    int scoreOfParentheses(string s) {
        int ans=0;
        int depth=0;
        int n = s.length();
        for(int i =0;i<n;i++)
        {
            if(s[i]=='(')
            {
                depth++;
            }
            else   // )
            {
                depth--;
                if( i>=0 && s[i-1]=='(')
                {
                    ans+=1<<depth;
                }
            }
        }
        return ans;
        
    }
};