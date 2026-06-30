// //Leetcode:1358. Number of Substrings Containing All Three Characters
// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
// Example 3:

// Input: s = "abc"
// Output: 1
 

// Constraints:

// 3 <= s.length <= 5 x 10^4
// s only consists of a, b or c characters.

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> mp(3 , 0);
        int j =0;
        int n =s.size();
        int i =0;
        int ans=0;
        while(j<n)
        {
             int  char_idx = s[j]-'a';
             mp[char_idx]++;
            while(mp[0]>0 && mp[1]>0 && mp[2]>0)
            {
            ans+=(n-j);
            mp[s[i]-'a']--;
             i++;   
            }
            j++;
        }   
        return ans; 
    }
};