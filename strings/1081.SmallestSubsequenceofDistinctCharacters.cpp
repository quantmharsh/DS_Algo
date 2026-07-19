// //Leetcode:1081. Smallest Subsequence of Distinct Characters
// Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

 

// Example 1:

// Input: s = "bcabc"
// Output: "abc"
// Example 2:

// Input: s = "cbacdcbc"
// Output: "acdb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.

class Solution {
public:
//Approach:get the last occurence of each charactr
//traverse over all
    string smallestSubsequence(string s) {

        int n = s.size();
        vector<bool> taken(26 ,false);
        vector<int> lastIndex(26 ,0);
        string result;

        for(int i =0;i<n;i++)
        {
            int char_idx=s[i]-'a';
            lastIndex[char_idx]=i;
        }

        for(int i =0;i<n;i++)
        {
            char ch =s[i];
             int char_idx=s[i]-'a';
              if(taken[char_idx] == true) continue;
            while(result.size()>0 && result.back()> ch && lastIndex[result.back()-'a'] > i)
            {
                taken[result.back()-'a']=false;
                result.pop_back();
            }
            result.push_back(ch);
            taken[ch-'a']=true;
        }
        return result;

        
    
    }
};