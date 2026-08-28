// //Leetcode:3720. Lexicographically Smallest Permutation Greater Than Target
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given two strings s and target, both having length n, consisting of lowercase English letters.

// Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.

// A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.

 

// Example 1:

// Input: s = "abc", target = "bba"

// Output: "bca"

// Explanation:

// The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
// The lexicographically smallest permutation that is strictly greater than target is "bca".
// Example 2:

// Input: s = "leet", target = "code"

// Output: "eelt"

// Explanation:

// The permutations of s (in lexicographical order) are "eelt", "eetl", "elet", "elte", "etel", "etle", "leet", "lete", "ltee", "teel", "tele", and "tlee".
// The lexicographically smallest permutation that is strictly greater than target is "eelt".
// Example 3:

// Input: s = "baba", target = "bbaa"

// Output: ""

// Explanation:

// The permutations of s (in lexicographical order) are "aabb", "abab", "abba", "baab", "baba", and "bbaa".
// None of them is lexicographically strictly greater than target. Therefore, the answer is "".
 

// Constraints:

// 1 <= s.length == target.length <= 300
// s and target consist of only lowercase English letters.
class Solution {
public:
    //Approach:Using hashmap+greedy+backtracking
    //try to fill ch if it is equal to ch in target at index i or greater
    //if ch is less then target i then continue because it will become smaller then target
    //when i =target length but we havent  find ans then pop last inserted char and try another character greater then popped character to finnd ans
    string result="";
    bool solve(string curr , string target , vector<int>& count , bool greater  , int i)
    {
        //Base case
        if(i==target.length())
        {
            if(greater==true)
            {
                result=curr;
                return true;
            }
            return false;
        }
        for(char ch='a';ch<='z';ch++)
        {
            if(count[ch-'a']==0)
            {
                continue;
            }
            if(greater==false && ch<target[i])
            {
                continue;
            }
            curr.push_back(ch); 
            count[ch-'a']--;
            //check that if after inserting ch in curr is  curr>target.
            //if ch >target[i] that means we got our greater ans. now just store characters directally in sorted oreder
            bool isGreater=ch>target[i]||greater;
            if(solve(curr , target ,count ,isGreater, i+1))
            {
                
                return true;
            }
            //not found
            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26 ,0);
        string curr;
        for(char &ch: s)
        {
            count[ch-'a']++;
        }
        bool greater=false;
        solve(curr, target , count ,greater , 0  );
        return result;
    }
};