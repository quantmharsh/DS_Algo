// //Leetcode:648. Replace Words
// In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

// Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

// Return the sentence after the replacement.

 

// Example 1:

// Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"
// Example 2:

// Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
// Output: "a a b c"
 

// Constraints:

// 1 <= dictionary.length <= 1000
// 1 <= dictionary[i].length <= 100
// dictionary[i] consists of only lower-case letters.
// 1 <= sentence.length <= 106
// sentence consists of only lower-case letters and spaces.
// The number of words in sentence is in the range [1, 1000]
// The length of each word in sentence is in the range [1, 1000]
// Every two consecutive words in sentence will be separated by exactly one space.
// sentence does not have leading or trailing spaces.

class Solution {
public:

    //Approach: Using Trie
    //since we need to find whether there exists derivative for word in dictionary .
    //so we will insert dictionary word in trie structure
    //trie structure will have pointer with 26 size  and iswordend boolean value to store whether it is the last character of word inserted 
    //this will help us in returning  root from dictionary 
    //while searching sentence words we will convert it into stringstream
    //then  search for each word 
    //if we found that word  doesnt exist inr oot then return complete word
    //else we will move till character which we are getting in dictionary
    //if that currentnode iswordend=true means we have reached best  root possible and then we will return word till basiaclly substr 

    struct trieNode{
        bool isWordEnd;
        trieNode * children[26];
    };

        trieNode* getNode()
        {
            trieNode * root= new trieNode();
            root->isWordEnd=false;
            for(int i =0;i<26;i++)
            {
                root->children[i]=NULL;
            }
            return root;
        }

        trieNode* root;

        void insert(string word)
        {
            trieNode* currNode= root;
            for(int i =0;i<word.size();i++)
            {
                 int char_idx=word[i]-'a';
                 if(currNode->children[char_idx]==NULL)
                 {
                    currNode->children[char_idx]=getNode();
                 }  
                 currNode=currNode->children[char_idx];
            }
            currNode->isWordEnd=true;
        }
        string search(string word)
        {
            trieNode* currNode= root;
            for(int i =0;i<word.size();i++)
            {
                int char_idx=word[i]-'a';
                //if word root doesnt exists in dictionary
                if(currNode->children[char_idx]==NULL)
                {
                    return word;
                }
                currNode=currNode->children[char_idx];
                if(currNode->isWordEnd==true)
                {
                    return word.substr(0 ,i+1);
                }
            }
            return word;
        }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
    
    stringstream ss(sentence);
    string ans;
    string word;
    root=getNode();    
    for(auto word: dictionary)
    {
        insert(word);
    }
    while(getline(ss,word , ' '))
    {
        ans+=search(word)+' ';
    }


//remove last space
    ans.pop_back();
    return ans;
        
    }
};