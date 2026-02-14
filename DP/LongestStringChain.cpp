// //Leetcode:1048 Longest String Chain
// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

 

// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
// Example 3:

// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of lowercase English letters.

class Solution {
public:
    //Approach 1: Using Recursion+Memoizztion
    //Same approach as LIS
    int t[1001][1001];
    int n;
    bool isPredecessor(string &word1 , string &word2)

    {
        int M =word1.length();
        int N=word2.length();
        if(N-M!=1)
        {
            return false;
        }
        int i =0,j=0;
        while(i<M && j<N)
        {
            if(word1[i]==word2[j])
            {
                i++;
            }
            j++;
        }
        return i==M;
    }
    int solve(int prev , int index ,vector<string>& words )
    {
        if(index==n)
        {
            return 0;
        }
        
        if(prev!=-1 && t[prev][index]!=-1)
        {
            return t[prev][index];
        }
        int take=0;
        if(prev==-1 || isPredecessor(words[prev] , words[index]))
        {
            take =1+solve(index , index+1 , words);
        }
        int skip =solve(prev ,index+1 , words);
        if(prev!=-1)
        {   
           t[prev][index]=max(take ,skip);
        }

        return max(take ,skip);

    }
    static bool sortBySize(string &word1 , string &word2)
    {
        return word1.length()<word2.length();
    }
    int longestStrChain(vector<string>& words) {
        n=words.size();
        memset(t , -1  ,sizeof(t));
        sort(begin(words) ,end(words) ,sortBySize);
        return solve(-1 ,0 , words);


        
    }
};