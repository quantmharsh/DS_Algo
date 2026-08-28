// //Leetcode:3734. Lexicographically Smallest Palindromic Permutation Greater Than Target
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given two strings s and target, each of length n, consisting of lowercase English letters.

// Return the lexicographically smallest string that is both a palindromic permutation of s and strictly greater than target. If no such permutation exists, return an empty string.

 

// Example 1:

// Input: s = "baba", target = "abba"

// Output: "baab"

// Explanation:

// The palindromic permutations of s (in lexicographical order) are "abba" and "baab".
// The lexicographically smallest permutation that is strictly greater than target is "baab".
// Example 2:

// Input: s = "baba", target = "bbaa"

// Output: ""

// Explanation:

// The palindromic permutations of s (in lexicographical order) are "abba" and "baab".
// None of them is lexicographically strictly greater than target. Therefore, the answer is "".
// Example 3:

// Input: s = "abc", target = "abb"

// Output: ""

// Explanation:

// s has no palindromic permutations. Therefore, the answer is "".

// Example 4:

// Input: s = "aac", target = "abb"

// Output: "aca"

// Explanation:

// The only palindromic permutation of s is "aca".
// "aca" is strictly greater than target. Therefore, the answer is "aca".
 

// Constraints:

// 1 <= n == s.length == target.length <= 300
// s and target consist of only lowercase English letters.
class Solution {
public:
    //Approach:Hashmap+Backtracking
    //This question is same as 3720. Only twist here is we have to take palindromic permutation
    //so as we do in other palindromic question  here also we will build only left part
    //and then append reverse(left part) into it 
    //  for palindrome we find half count of each character . and check if any char haas countodd
    //if only 1 char have count odd then palindrome is possible append it after left part
    // if  more then  1 char have count odd then it is impossible to build palindromic string 
    //so return empty string
    // here just we will have 2 major changes 
    // in count store half frequency count
    //and when curr length reaches n/2 length then append any mid char and reverse of right part

    int halfLength=0;
    char midChar='%';
    string result="";

    bool solve(string curr ,vector<int>& halfCount , string target , int i , bool greater)
    {
        //Base case 
        if(i==halfLength)
        {
            string leftpart= curr;
            string candidateans= leftpart;
            string rightpart=leftpart;
            reverse(rightpart.begin() , rightpart.end());
            if(midChar!='%')
            {
                candidateans+=midChar;
            }
            candidateans.append(rightpart);
            if(candidateans > target)
            {
                result=candidateans;
                cout<<"Result"<<result<<endl;
                return true;
            }
            return false;

        }

    for(char ch='a' ;ch<='z';ch++)
    {
        if(halfCount[ch-'a']<1)
        {
            continue;
        }
        if(greater==false && ch<target[i])
        {
            continue;
        }
        curr.push_back(ch);
        halfCount[ch-'a']--;
        bool isGreater= greater || ch>target[i];
        if(solve(curr , halfCount ,target ,i+1 ,isGreater))
        {
            return true;
        }
        curr.pop_back();
        halfCount[ch-'a']++;
    }
    return false;
    }
    
    string lexPalindromicPermutation(string s, string target) {
        int n=s.length();
        vector<int> count(26 , 0);
        //calculate frequency;
        for(char &ch: s)
        {
            count[ch-'a']++;
        }
        int oddCount =0;
        
        for(int i =0;i<26;i++)
        { 
            if(count[i]%2==1)
            {
                oddCount++;
                midChar=i+'a';
            }

        }
        if(oddCount>1)
        {
            return "";
        }
        vector<int> halfCount(26 , 0);
        for(int i =0;i<26;i++)
        {
            halfCount[i]=count[i]/2;
        }
        string curr=result;
        halfLength=n/2;

        solve(curr ,halfCount , target  , 0 ,false);
        return result;
        
    }
};