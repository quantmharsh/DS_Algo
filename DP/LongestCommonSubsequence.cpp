// //Leetcode:1143 .Longest Common Subsequence
// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

 

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.
 

// Constraints:

// 1 <= text1.length, text2.length <= 1000
// text1 and text2 consist of only lowercase English characters.

class Solution {
public:
    // Subtopic: DP on String
    //Approach 1:Using Recursion+Memoization
    //we have three scenarios 
    //1. is text1[i]==text2[j] then increase count by 1 and move both indexes
    //2. if not then check for  2 condition keep text1[i] and move j to  text2[j+1]
    //3. or move move text1[i+1] and keep text2[j] compare this 2
    //since 2 variables are changing  so we will have 2d DP
    //at last return max  of both scenarios 2 ,3  
   
    int m ,n;
    // int solve(int i , int j , string &text1 ,string &text2)
    // {
    //     //base condition
    //     if(i>=m  || j>=n)
    //     {
    //         return 0;
    //     }
    //     if(t[i][j]!=-1)
    //     {
    //         return t[i][j];
    //     }
    //     if(text1[i]==text2[j])
    //     {
    //        return  t[i][j]=1+solve(i+1 , j+1 , text1 , text2);
    //     }
      
    //     return t[i][j]=max(solve(i+1 , j , text1 ,text2) , solve(i ,j+1, text1 ,text2));

    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     memset(t ,-1 ,sizeof(t));
    //     m=text1.size();
    //     n=text2.size();
    //     return solve( 0 , 0 , text1 , text2);

        
    // }


    //Approach2:Using Bottom Up approach
    //we will be using 2d dp 
    //and assign 0 value to index where i =0 or j=0.since LCS is not possible  if anyone is 0
    //and for others we will loop all indexe
    //whenever we find text1[i]=text2[j] then t[i][j]=1+t[i-1][j-1]
    //else  t[i][j]=max(t[i][j-1] ,t[i-1][j]);
        int longestCommonSubsequence(string text1, string text2) {
            
        m=text1.size();
        n=text2.size();
        vector<vector<int>>t(m+1 , vector<int>(n+1));
       for(int i =0;i<m;i++)
       {
        t[i][0]=0;
       }
       for(int j =0;j<n;j++)
       {
        t[0][j]=0;
       }
       for(int i =1;i<m+1;i++)
       {
        for(int j =1;j<n+1;j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                t[i][j]=1+t[i-1][j-1];

            }
            else{
                t[i][j]=max(t[i-1][j] ,t[i][j-1]);
            }
        }
       }
       return t[m][n];


        
    }
};