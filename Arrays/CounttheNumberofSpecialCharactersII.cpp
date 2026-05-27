// //Leetcode: 3121. Count the Number of Special Characters II
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.

// Return the number of special letters in word.

 

// Example 1:

// Input: word = "aaAbcBC"

// Output: 3

// Explanation:

// The special characters are 'a', 'b', and 'c'.

// Example 2:

// Input: word = "abc"

// Output: 0

// Explanation:

// There are no special characters in word.

// Example 3:

// Input: word = "AbBCab"

// Output: 0

// Explanation:

// There are no special characters in word.

 

// Constraints:

// 1 <= word.length <= 2 * 105
// word consists of only lowercase and uppercase English letters.

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>LastlowerCase(26,-1);
        vector<int>FirstupperCase(26,-1);
        int cnt=0;
        for(int i =0;i<word.size();i++)
        {
            char ch = word[i];
            if(islower(ch))
            {
                LastlowerCase[ch-'a']=i;

            }
            else if(FirstupperCase[ch-'A']== -1 ){
                FirstupperCase[ch-'A']=i;
            }
        }

        for(int i=0;i<26;i++)
        {
            if( LastlowerCase[i] !=-1 && FirstupperCase[i]!=-1 &&LastlowerCase[i] <FirstupperCase[i])
            {
                    cnt++;
            }
        }
        return cnt;
     

        
    }
};