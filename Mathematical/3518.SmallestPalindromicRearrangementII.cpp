// //Leetcode:3518. Smallest Palindromic Rearrangement II
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given a palindromic string s and an integer k.

// Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.

// Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.

 

// Example 1:

// Input: s = "abba", k = 2

// Output: "baab"

// Explanation:

// The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
// Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".
// Example 2:

// Input: s = "aa", k = 2

// Output: ""

// Explanation:

// There is only one palindromic rearrangement: "aa".
// The output is an empty string since k = 2 exceeds the number of possible rearrangements.
// Example 3:

// Input: s = "bacab", k = 1

// Output: "abcba"

// Explanation:

// The two distinct palindromic rearrangements of "bacab" are "abcba" and "bacab".
// Lexicographically, "abcba" comes before "bacab". Since k = 1, the output is "abcba".
 

// Constraints:

// 1 <= s.length <= 104
// s consists of lowercase English letters.
// s is guaranteed to be palindromic.
// 1 <= k <= 106 

class Solution {
public:
    //Approach: Factorization+Cumulative sum+ Binary search
    //find the mid of string 
    //count occurence of each character in string
    //now we need to find kth  smallest palindromic string 
    //so we will use p&C here
    //nCr formula
    //at ith first try with smallest character 
    //then find no of ways that can we created with starting with that character
    //check if ways > k then kth smallest palidrome will be in . in ans push ith character
    //then go to i+1 index there also do same 
    //if k >ways that means when starting string with ith char then we cant find solution so reduce k to k=k-way
    //that means in next block we will get (when starting with 2nd smallest char  not with 1st smallest char)
    //at last add mid to string then reverse firsthalf string and add to answer

    long long nCr( int n , int r , int k)
    {
        r=min(r , n-r);
        long long result=1;
        for(int i=1;i<=r;i++)
        {
                result=result*(n-r+i)/i;
                if(result>=k)
                {
                    return k;
                }
        }
        return result;
    }
    string smallestPalindrome(string s, int k) {
  
        int n =s.size();
        char mid=' ';
        vector<int> count(26 ,0);
        bool  isPossible=false;
        //store mid if length in  odd in even case this will not called 
        if(n%2==1)
        {
            mid= s[n/2];
        }
        //count occurence of all characters in string dont include mid character if length is odd
        for(int i =0;i<n;i++)
        {
            if(i==n/2 && n%2==1)
            {
                continue;
            }
            count[s[i]-'a']+=1;
        }

        //take half length for that we reduce its count to half
        for(int i=0;i<26;i++)
        {
             count[i]/=2;
        }
        int  firstHalf= n/2;
        string halfString;
        //now we need to fill all slots 
        for(int i =0;i<firstHalf;i++)
        {
            for(int j =0;j<26;j++)
            {
                if(count[j]>0)
                {
                    count[j]-=1;
                    long long ways=1;
                    long long  letters=0;
                    //calculate letters available to buid furhter string
                    for(int i =0;i<26;i++)
                    {
                        letters+=count[i];
                    }
                     for(int c=0;c<26;c++)
                     {      if(count[c]>0)
                     {
                           ways*=nCr(letters , count[c] , k);
                           letters-=count[c];
                     }
                           if(ways>=k)
                           {
                            break;
                           }
                     }
                    //our answer will be in this ways only put this char and break and find for next index 
                     if(ways>=k)
                     {
                        halfString.push_back(j+'a');
                        isPossible=true;
                        break;

                     }
                     //start with another character.since not picked character increase its count to original 
                     k-=ways;
                     count[j]+=1;
                 
                }
            }
                    if(isPossible==false)
        {
            return "";
        }
        }

        string rev= halfString;
        if(mid!=' ')
        {
            halfString.push_back(mid);
        }
        reverse(rev.begin() ,rev.end());
         halfString+=rev;
         return halfString; 
        
        
    }
};