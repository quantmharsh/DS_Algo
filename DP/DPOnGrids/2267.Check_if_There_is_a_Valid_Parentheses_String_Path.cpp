// //Leetcode:2267. Check if There Is a Valid Parentheses String Path
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

// It is ().
// It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
// It can be written as (A), where A is a valid parentheses string.
// You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:

// The path starts from the upper left cell (0, 0).
// The path ends at the bottom-right cell (m - 1, n - 1).
// The path only ever moves down or right.
// The resulting parentheses string formed by the path is valid.
// Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.

 

// Example 1:


// Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
// Output: true
// Explanation: The above diagram shows two possible paths that form valid parentheses strings.
// The first path shown results in the valid parentheses string "()(())".
// The second path shown results in the valid parentheses string "((()))".
// Note that there may be other valid parentheses string paths.
// Example 2:


// Input: grid = [[")",")"],["(","("]]
// Output: false
// Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 100
// grid[i][j] is either '(' or ')'.
class Solution {
public:
    //Approach: Grid DP-Recursion+Memoization
    //traverse in both down and right direction if anyone of them return true then return true
    //we will use 3d dp here since three variables are changing 
    //We will have some early checks 
    // if m+n-1 is  odd then definetly we cant get pair of () so return false
    // if  grid[0][0]=) or grid[m-1][n-1]==( then also retrn false
    //while recursion we will stoer openbrackt count if grid i,j =( else reduce openbracketcount 
    // if  openbracketount is in negatove then also return false
    //and memorize wherever we are returing anything
    int  dp[101][101][201];

    bool solve(int i , int j , int openBracketCount , vector<vector<char>>& grid , int m , int n)
    {
      //  cout<<"open bracked"<<openBracketCount<<endl;
        grid[i][j]=='('?openBracketCount++ : openBracketCount--;

        if(openBracketCount<0)
        {
            return false;
        }
        if(dp[i][j][openBracketCount]!=-1)
        {
            return dp[i][j][openBracketCount];
        }
        //base case 
        if(i==m-1 && j==n-1)
        {
           // cout<<"open bracket last index"<<openBracketCount<<endl;
            return dp[i][j][openBracketCount]= openBracketCount==0;
        }
        bool right=false;
        bool down =false;
        //Mpve right -> increase j+1
        if(j+1<n)
        {
           right= solve(i , j+1 , openBracketCount ,grid , m ,n);
        }
        //Move down -> increase i+1
        if(i+1<m)
        {
          down=  solve(i+1 , j , openBracketCount , grid , m , n);
        }
        return dp[i][j][openBracketCount]=right || down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m =grid.size();
        int n= grid[0].size();
        int openBracketCount=0;
        
        if(grid[0][0]==')' || grid[m-1][n-1]=='(')
        {
            return false;
        }  
        //odd length
        if((m+n-1)%2!=0)
        {
            return false;
        }
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , openBracketCount , grid , m ,n);
        
    }
};