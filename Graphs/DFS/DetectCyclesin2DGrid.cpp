// //Leetcode:1559. Detect Cycles in 2D Grid
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

// A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

// Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

// Return true if any cycle of the same value exists in grid, otherwise, return false.

 

// Example 1:



// Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
// Output: true
// Explanation: There are two valid cycles shown in different colors in the image below:

// Example 2:



// Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
// Output: true
// Explanation: There is only one valid cycle highlighted in the image below:

// Example 3:



// Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
// Output: false
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 500
// grid consists only of lowercase English letters.


class Solution {
public:
 // Approach: DFS Traversal for Cycle Detection in Grid
    //
    // Idea:
    // We treat the grid as a graph where each cell is a node.
    // We perform DFS from every unvisited cell and try to detect a cycle.
    //
    // A cycle exists if:
    // - While traversing, we reach a cell that is already visited
    // - AND it is NOT the parent cell (the cell we came from)
    //
    // Steps:
    // 1. Traverse the grid using two loops (i, j)
    // 2. If a cell is not visited, start DFS from that cell
    // 3. In DFS:
    //    - Mark current cell as visited
    //    - Explore all 4 directions (up, down, left, right)
    //    - For each valid neighbor:
    //         • If it is the parent → skip
    //         • If it is already visited → cycle found
    //         • Else → continue DFS
    //
    // Time Complexity: O(m * n)
    // Space Complexity: O(m * n) for visited + recursion stack

    vector<vector<int>>directions ={{1,0},{-1,0} ,{0,1},{0,-1}};
     bool checkCycleDfs(int i , int j , int parent_i , int parent_j , int m , int n ,vector<vector<char>>& grid,  vector<vector<bool>>& visited )
     {
        if(visited[i][j])
        {
            return true;
        }
        visited[i][j]=true;
        //check in all four directions 
        for(auto it:directions)
        {
            int r=i+it[0];
            int c=j+it[1];
            //check whethernew indexes are vaild or not
            if(r>=0 &&r<m &&c>=0 && c<n && grid[r][c]==grid[i][j] )
            {
                if(r==parent_i && c==parent_j)
                {
                    continue;
                }
                if(checkCycleDfs(r,c,i,j,m,n,grid,visited))
                   {
                    return true;
                   }
                
            }
        }


        return false;


     }
    bool containsCycle(vector<vector<char>>& grid) {
        int  m=grid.size();
        int n =grid[0].size();
        vector<vector<bool>> visited(m , vector<bool>(n , false));

        

        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && checkCycleDfs(i ,j,i,j, m ,n,grid ,visited))
                {
                    return true;
                }
            }
        }
        return false;

        
        
    }
};