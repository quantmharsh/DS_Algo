// //Leetcode:3863. Minimum Operations to Sort a String
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a string s consisting of lowercase English letters.

// In one operation, you can select any substring of s that is not the entire string and sort it in non-descending alphabetical order.

// Return the minimum number of operations required to make s sorted in non-descending order. If it is not possible, return -1.

 

// Example 1:

// Input: s = "dog"

// Output: 1

// Explanation:​​​​​​​

// Sort substring "og" to "go".
// Now, s = "dgo", which is sorted in ascending order. Thus, the answer is 1.
// Example 2:

// Input: s = "card"

// Output: 2

// Explanation:

// Sort substring "car" to "acr", so s = "acrd".
// Sort substring "rd" to "dr", making s = "acdr", which is sorted in ascending order. Thus, the answer is 2.
// Example 3:

// Input: s = "gf"

// Output: -1

// Explanation:

// It is impossible to sort s under the given constraints. Thus, the answer is -1.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only lowercase English letters.

class Solution {
public:
    //Approach: Observation
    //String can be sorted only max to max in 4 ways
    //1.) if string is already sorted then return 0; for ex: ab 
    //2.) if string is of length 2 then return -1 ; for ex ba .we cant sort it
    //3.) min char is at start or max char is at  end  then return 1 . for ex arcd or cdar
    //4.)Max char is beginnning and min char in at end  then return 3. for ex rcda
    //5. Else for every case return 2. for ex racd
    //T.C : O(n)
    //S.C : O(1)
    int minOperations(string s) {
    
    char  min_char= *min_element(s.begin() ,s.end());
    char max_char= *max_element(s.begin() ,s.end());
    int n =s.length();
    if(is_sorted(s.begin(), s.end()))
    {
        return 0;
    }
    if(n==2)
    {
        return -1;
    }
    if(s[0]==min_char || s[n-1]==max_char)
    {
        return 1;
    }
    
    char mid_min_char= *min_element(s.begin()+1 , s.end()-1);
    char mid_max_char= *max_element(s.begin()+1 , s.end()-1);
    if(s[0]>mid_max_char && s[n-1] <mid_min_char)
    {
        return 3;
    }
    return 2;

    }
};