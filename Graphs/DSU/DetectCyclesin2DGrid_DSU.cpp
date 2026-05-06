// //leetcode:1559.Detect Cycles in 2D Grid
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

 /*
    ------------------------------------------------------------
    Approach: Using DSU (Disjoint Set Union)
    ------------------------------------------------------------
    - Treat each cell of the grid as a node in a graph.
    - Connect nodes (cells) if they are adjacent AND have the same character.
    - While connecting, if two nodes already belong to the same component,
      it means adding this edge creates a cycle.

    ------------------------------------------------------------
    Intuition:
    ------------------------------------------------------------
    - A cycle in a graph exists when we try to connect two nodes that are already connected.
    - DSU helps us efficiently track connected components.
    - If find(u) == find(v), it means u and v are already connected,
      so adding this connection forms a cycle.

    - Since the grid is undirected, checking all 4 directions can cause duplicate edges.
      So we only check:
          → Right (i, j+1)
          → Down  (i+1, j)
      This ensures each edge is processed only once.

    ------------------------------------------------------------
    Algorithm:
    ------------------------------------------------------------
    1. Initialize DSU:
        - Each cell is its own parent.
        - Rank array initialized to 0.

    2. Traverse the grid:
        - For each cell (i, j):
            - Check right and down neighbors.

    3. For each valid neighbor (r, c):
        - If grid[i][j] == grid[r][c]:
            - Convert both cells to 1D indices:
                u = i * n + j
                v = r * n + c

            - If find(u) == find(v):
                → Cycle detected → return true

            - Else:
                → union(u, v)

    4. If no cycle found after full traversal → return false

    ------------------------------------------------------------
    Time Complexity: O(m * n * α(n))  ≈ O(m * n)
    Space Complexity: O(m * n)
    ------------------------------------------------------------
    */


class Solution {
public:
    vector<int>rank;
    vector<int>parent;
    int find(int x)

    {
        if(x==parent[x])
        {
            return x;
        }
        return find(parent[x]);
    }

    void unionByRank(int x , int y)
    {
        int x_parent=find(x);
        int y_parent=find(y);
        if(rank[x_parent]>rank[y_parent])
        {
            parent[y_parent]=x_parent;
        }
        else if(rank[y_parent]>rank[x_parent])
        {
            parent[x_parent]=y_parent;
        }
        else{
            parent[y_parent]=x_parent;
            rank[x_parent]++;
        }
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int size=m*n;
        parent.resize(size);
        rank.resize(size,0);
        for(int i =0;i<size;i++)
        {
            parent[i]=i;

        }
        vector<vector<int>> directions={{0,1} ,{1,0}};
        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                for(auto it:directions)
                {
                    int r=i+it[0];
                    int c=j+it[1];
                    //check whether r nd c are valid
                    if(r>=0 &&r<m && c>=0 &&c<n)
                    {

                        if(grid[i][j]==grid[r][c])
                        {
                            int u =i*n+j;
                            int v=r*n+c;
                            int u_parent=find(u);
                            int v_parent=find(v);
                            if(u_parent==v_parent)
                            {
                                return true;
                            }
                            unionByRank(u ,v);

                        }
                    }
                

                } 
            }

        }
        return false;
       
        
    }
};