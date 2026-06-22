// //Leetcode:1189. Maximum Number of Balloons
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

// Example 1:



// Input: text = "nlaebolko"
// Output: 1
// Example 2:



// Input: text = "loonbalxballpoon"
// Output: 2
// Example 3:

// Input: text = "leetcode"
// Output: 0
 

// Constraints:

// 1 <= text.length <= 104
// text consists of lower case English letters only.
 

// Note: This question is the same as 2287: Rearrange Characters to Make Target String.
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>charCount(26,0);
        for(char ch: text)
        {
            int char_idx=ch-'a';
            charCount[char_idx]+=1;

        }
     return    min({charCount['b'-'a'] , charCount['a'-'a'] ,charCount['l'-'a']/2 , charCount['o'-'a']/2 , charCount['n'-'a']});
        
    }
};