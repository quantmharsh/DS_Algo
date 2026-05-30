// //Leetcode: 3093. Longest Common Suffix Queries
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given two arrays of strings wordsContainer and wordsQuery.

// For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.

// Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].

 

// Example 1:

// Input: wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]

// Output: [1,1,1]

// Explanation:

// Let's look at each wordsQuery[i] separately:

// For wordsQuery[0] = "cd", strings from wordsContainer that share the longest common suffix "cd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
// For wordsQuery[1] = "bcd", strings from wordsContainer that share the longest common suffix "bcd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
// For wordsQuery[2] = "xyz", there is no string from wordsContainer that shares a common suffix. Hence the longest common suffix is "", that is shared with strings at index 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
// Example 2:

// Input: wordsContainer = ["abcdefgh","poiuygh","ghghgh"], wordsQuery = ["gh","acbfgh","acbfegh"]

// Output: [2,0,2]

// Explanation:

// Let's look at each wordsQuery[i] separately:

// For wordsQuery[0] = "gh", strings from wordsContainer that share the longest common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
// For wordsQuery[1] = "acbfgh", only the string at index 0 shares the longest common suffix "fgh". Hence it is the answer, even though the string at index 2 is shorter.
// For wordsQuery[2] = "acbfegh", strings from wordsContainer that share the longest common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
 

// Constraints:

// 1 <= wordsContainer.length, wordsQuery.length <= 104
// 1 <= wordsContainer[i].length <= 5 * 103
// 1 <= wordsQuery[i].length <= 5 * 103
// wordsContainer[i] consists only of lowercase English letters.
// wordsQuery[i] consists only of lowercase English letters.
// Sum of wordsContainer[i].length is at most 5 * 105.
// Sum of wordsQuery[i].length is at most 5 * 105.
class Solution {
public:
    struct  trieNode {
        int index;
        trieNode *children[26];
         ~trieNode() {
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };

    trieNode* getNode(int i)
    {
        trieNode *temp= new trieNode();
        temp->index=i;
        for(int i =0;i<26;i++)
        {
            temp->children[i]=NULL;
        }
        return temp;
    }

    //Since trie work on prefix but we need to work with  suffux so we will move in reverse order 
    //pick a character  find it charater index
    //then search in root level whether that char_index is null or not if null then  store this char
    //and  if not null then move downward from root to that character children
    //also update index value 
    void insertInTrie(trieNode* root , int i , vector<string>& wordsContainer)
    {
            string word=wordsContainer[i];
            int n =word.size();
            for(int j =n-1;j>=0;j--)
            {
                int char_idx= word[j]-'a';

                
                if(root->children[char_idx]==NULL)
                {
                root->children[char_idx]=getNode(i);
                }
                root=root->children[char_idx];
                if(wordsContainer[root->index].size() > n)
                {
                    root->index=i;
                }




            }

    }
    //by default we will  have result as root->index which will be min length of any word in a container 
    //if we dont get matching suffix then we will return same result else will update it by index

    int searchQuery(trieNode* root  ,string word)
    {
        int result = root->index;
        int n =word.size();
        for(int i =n-1;i>=0;i--)
        {
             int char_idx= word[i]-'a';
             if(root->children[char_idx]==NULL)
             {
                return result;
             }
             root=root->children[char_idx];
             result= root->index;
            
        }
        return result;


    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        
        int n =wordsContainer.size();
        int  m =wordsQuery.size();
        vector<int>result(m);

        trieNode* root = getNode(0);
        //Insert  words container into trie structure;
        for(int i =0;i<n ;i++)
        {
            //update index of root to get smallest index when 
            int index=root->index;
            if(wordsContainer[index].size()>wordsContainer[i].size())
            {
                root->index=i;
            }
            insertInTrie(root ,i,wordsContainer);
        }

        //Search  WordsQuery in our trie data structure which we created 
        for(int i =0;i<m;i++)
        {
            result[i]=searchQuery( root  , wordsQuery[i]);
        }
       delete root;   // invokes destructor
        return result;

    }
};