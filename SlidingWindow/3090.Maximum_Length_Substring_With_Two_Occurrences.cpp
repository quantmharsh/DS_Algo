// //Leetcode:3090. Maximum Length Substring With Two Occurrences

// Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
 

// Example 1:

// Input: s = "bcbbbcba"

// Output: 4

// Explanation:

// The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
// Example 2:

// Input: s = "aaaa"

// Output: 2

// Explanation:

// The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
 

// Constraints:

// 2 <= s.length <= 100
// s consists only of lowercase English letters.

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char , int> mp;
        int l=0;
        int r=0;
        int ans=0;
   
        int n=s.length();
        while(r<n)
        {
            mp[s[r]]++;
            while(l<=r && mp[s[r]]>2)
            {
                mp[s[l]]--;
                l++;
            }
            ans=max(ans ,r-l+1);
            r++;
        }
        return ans;


        
    }
};