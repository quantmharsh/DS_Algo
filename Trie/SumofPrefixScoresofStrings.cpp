// //leetcode:2416. Sum of Prefix Scores of Strings
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array words of size n consisting of non-empty strings.

// We define the score of a string term as the number of strings words[i] such that term is a prefix of words[i].

// For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
// Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].

// Note that a string is considered as a prefix of itself.

 

// Example 1:

// Input: words = ["abc","ab","bc","b"]
// Output: [5,4,3,2]
// Explanation: The answer for each string is the following:
// - "abc" has 3 prefixes: "a", "ab", and "abc".
// - There are 2 strings with the prefix "a", 2 strings with the prefix "ab", and 1 string with the prefix "abc".
// The total is answer[0] = 2 + 2 + 1 = 5.
// - "ab" has 2 prefixes: "a" and "ab".
// - There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
// The total is answer[1] = 2 + 2 = 4.
// - "bc" has 2 prefixes: "b" and "bc".
// - There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
// The total is answer[2] = 2 + 1 = 3.
// - "b" has 1 prefix: "b".
// - There are 2 strings with the prefix "b".
// The total is answer[3] = 2.
// Example 2:

// Input: words = ["abcd"]
// Output: [4]
// Explanation:
// "abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
// Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 = 4.
 

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 1000
// words[i] consists of lowercase English letters.

class Solution {
public:

    //Approach:Using Trie
    //insert as we do ggenetrally in trie . but while inseting maintaincount of howmany time that  character is getting called
    //while searchng return sum of all count for each word

    struct trieNode {
        int count;
        trieNode* children[26];
    };
    trieNode * root;
    trieNode* getNode()
    {
        trieNode* root = new trieNode();
        root->count=0; 
        for(int i =0;i<26;i++)
        {
            root->children[i]=NULL;
        }
        return root;
    }

    void insert(string word)
    {
        trieNode* currNode=root;
        for(int i =0;i<word.size();i++)
        {
            int char_idx=word[i]-'a';
            //if not present
            if(currNode->children[char_idx]==NULL)
            {
                currNode->children[char_idx]= getNode();
            }
            currNode->children[char_idx]->count+=1;
            currNode=currNode->children[char_idx];
        }
    }
    int search(string word)
    {
        trieNode* currNode = root;
        int result=0;
        for(int i =0;i<word.size();i++)
        {
            int char_idx=word[i]-'a';
            result+=currNode->children[char_idx]->count;
            currNode=currNode->children[char_idx];
            

        }
        return result;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n =words.size();
        root= getNode();
        vector<int>result(n);
        for(auto word: words)
        {
            insert(word);
        }
        for(int i =0;i<n;i++)
        {
            result[i]=search(words[i]);
        }
        return result;
        
        
    }
};