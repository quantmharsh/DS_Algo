// //Leetcode:208. Implement Trie (Prefix Tree)

// Medium
// Topics
// premium lock icon
// Companies
// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:

// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

// Example 1:

// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]

// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True
 

// Constraints:

// 1 <= word.length, prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3 * 104 calls in total will be made to insert, search, and startsWith.

class Trie {
public:

    struct trieNode {
        trieNode * children[26];
        bool isWordEnd ;
    };

        trieNode* getNode()
        {
            trieNode* root=  new trieNode();
            root->isWordEnd=false;
            for(int i =0;i<26;i++)
            {
                root->children[i]=NULL;
            }
            return root;
        }
    
    trieNode* root;
    Trie() {
        root= getNode();
    

        
    }
    
    void insert(string word) {
        int n =word.size();
        trieNode* currNode= root;
        for(int i =0;i<n;i++)
        {
            int char_idx=word[i]-'a';
            if(currNode->children[char_idx]==NULL)
            {
                    currNode->children[char_idx] =getNode(); 
            }
            currNode=currNode->children[char_idx];
        }
        currNode->isWordEnd=true;
         
    }
    
    bool search(string word) {
        int n =word.size();
        trieNode* currNode=root;
        for(int i =0;i<n;i++)
        {
            int char_idx=word[i]-'a';
            if(currNode->children[char_idx]==NULL)
            {
                return  false;
            }
          
           currNode= currNode->children[char_idx];
        }
        return (currNode!=NULL && currNode->isWordEnd==true);
        
        
    }
    
    bool startsWith(string prefix) {
        int n =prefix.size();
        trieNode* currNode=root;
        int i=0;
        for( i =0;i<n;i++)
        {
            int char_idx=prefix[i]-'a';
            if(currNode->children[char_idx]==NULL)
            {
                return false;
            }
            currNode=currNode->children[char_idx];
        }
     
     if(i==n)
     {
        return true;
     }
     return false;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */