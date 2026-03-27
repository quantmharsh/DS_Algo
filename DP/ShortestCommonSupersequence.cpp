// // GFG:Shortest Common Supersequence
// Given two strings s1 and s2, find the length of the smallest string which has both s1 and s2 as its sub-sequences.
// Note: s1 and s2 can have both uppercase and lowercase English letters.

// Examples:

// Input: s1 = "geek", s2 = "eke"
// Output: 5
// Explanation: String "geeke" has both string "geek" and "eke" as subsequences.
// Input: s1 = "AGGTAB", s2 = "GXTXAYB"
// Output: 9
// Explanation: String "AGXGTXAYB" has both string "AGGTAB" and "GXTXAYB" as subsequences.
// Input: s1 = "geek", s2 = "ek"
// Output: 4
// Explanation: String "geek" has both string "geek" and "ek" as subsequences.
// Constraints:
// 1 ≤ s1.size(), s2.size() ≤ 500
class Solution {
  public:
  //Approach:Using Recursion+Memoization
  //T.C : O(m*n)
  //S.C : O(m*n)
  //question is of type pick or not pick
  //Base case .if any of them become 0 then add remaining letters from another string into ans .
  //if s1 and s2 at n , m are save then pick any one and move both
  //if we pick letter from s1 then  go to next index . 
  //if pick letter from s2 then go to next index of s2

    int t[501][501];
    int solve(string &s1 ,string &s2 , int m , int n)
    {
        if(m==0 || n==0)
        {
            return m+n;
        }
        if(t[m][n]!=-1)
        {
            return t[m][n];
        }
        if(s1[m-1]==s2[n-1])
        {
           return  t[m][n]= 1+solve(s1 ,s2 , m-1 , n-1);
        }
        else
        {
           return t[m][n]= 1+min(solve(s1 ,s2 , m-1 , n) ,solve(s1 ,s2, m,n-1));
        }
        return 0;
        
    }
    //Approach 2: Using Bottom Up Approach 
    //we know that t[i][j] means scss till i and j 
    //so we will do same . for loop from i=0 to i<=m+1 and j=0 to j<=n+1
    //if i ==0 or j==0(Same condition which we did in recursion +memo).
    //we will return i+j
    //if s1[i-1]==s2[j-1] then at t[i][j]we will  store 1+t[i-1][j-1]
    //else t[i][j]=1+min(t[i-1][j] ,t[i][j-1])
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int m =s1.length();
        int n =s2.length();
        // memset(t ,-1 , sizeof(t));
        // return solve(s1 ,s2, m,n );
        vector<vector<int>> t(m+1 ,vector<int>(n+1));
        
        
        for(int i =0;i<m+1 ;i++)
        {
            for(int j =0;j<n+1;j++)
            {
                if(i==0 || j==0)
                {
                    t[i][j]=i+j;
                }
                else if(s1[i-1]==s2[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                }
                else {
                    t[i][j]=1+min(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[m][n];
        
    }
};