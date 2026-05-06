// //Leetcode:3742. Maximum Path Score in a Grid
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an m x n grid where each cell contains one of the values 0, 1, or 2. You are also given an integer k.

// You start from the top-left corner (0, 0) and want to reach the bottom-right corner (m - 1, n - 1) by moving only right or down.

// Each cell contributes a specific score and incurs an associated cost, according to their cell values:

// 0: adds 0 to your score and costs 0.
// 1: adds 1 to your score and costs 1.
// 2: adds 2 to your score and costs 1. ​​​​​​​
// Return the maximum score achievable without exceeding a total cost of k, or -1 if no valid path exists.

// Note: If you reach the last cell but the total cost exceeds k, the path is invalid.

 

// Example 1:

// Input: grid = [[0, 1],[2, 0]], k = 1

// Output: 2

// Explanation:​​​​​​​

// The optimal path is:

// Cell	grid[i][j]	Score	Total
// Score	Cost	Total
// Cost
// (0, 0)	0	0	0	0	0
// (1, 0)	2	2	2	1	1
// (1, 1)	0	0	2	0	1
// Thus, the maximum possible score is 2.

// Example 2:

// Input: grid = [[0, 1],[1, 2]], k = 1

// Output: -1

// Explanation:

// There is no path that reaches cell (1, 1)​​​​​​​ without exceeding cost k. Thus, the answer is -1.

 

// Constraints:

// 1 <= m, n <= 200
// 0 <= k <= 103​​​​​​​
// ​​​​​​​grid[0][0] == 0
// 0 <= grid[i][j] <= 2


class Solution {
public:
//Approach: Recusrsion+Memoization
// function(i, j, cost):

//     1. If out of bounds → return INT_MIN

//     2. Compute newcost

//     3. If newcost > k → return INT_MIN

//     4. If destination → return grid[i][j]

//     5. If dp[i][j][cost] exists → return it

//     6. down  = f(i+1, j, newcost)
//        right = f(i, j+1, newcost)

//     7. If both invalid → return INT_MIN

//     8. ans = grid[i][j] + max(down, right)

//     9. store dp[i][j][cost] = ans

//    10. return ans
    int solve(vector<vector<vector<int>>>& dp , vector<vector<int>>& grid , int k , int m , int n , int i , int j , int cost)
    {
        //base case
        if(i>=m || j>=n)
        {
            return INT_MIN;
        }

        int newcost=cost+(grid[i][j]>0?1:0);
              if(newcost >k)
        {
            return INT_MIN;
        }

         if(i==m-1 && j==n-1 && newcost <=k)
        {
                return grid[i][j];
        }

        if(dp[i][j][cost]!=-1)
        {
            return dp[i][j][cost];
        }
  
        
        

        int down =solve(dp , grid , k , m,n ,i+1 , j , newcost);
        int right=solve(dp , grid , k , m , n ,i , j+1 , newcost);
        int ans =max(down , right);
        if(ans==INT_MIN)
        {
            return dp[i][j][cost]= INT_MIN;
        }
       return  dp[i][j][cost]=ans+grid[i][j];
        

    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m+1 , vector<vector<int>>(n+1 , vector<int>(k+1 ,-1)) );
        
    int ans =solve(dp , grid , k , m ,n ,0,0,0);
    return  ans==INT_MIN ?-1:ans;
    }
};