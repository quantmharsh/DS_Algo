// //Leetcode 695 Max area of island
// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.
class UnionFind {
private:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;
    
public:
    UnionFind(int m, int n) {
        parent.resize(m*n);
        for(int i = 0; i<m*n; i++)
            parent[i] = i;
        
        size.resize(m*n, 1); //initially size of each group is 1 (itself)
        rank.resize(m*n, 0);
    }
    
    int find(int x) {
        if(parent[x] != x)
            return parent[x] = find(parent[x]); //path compression
        
        return x;
    }
    
    //this is the trick, we return size of group after uniting the nodes in a group
    //Union by rank compression
    int Union(int x, int y) {
        int p_x = find(x);
        int p_y = find(y);
        
        if(p_x == p_y)
            return this->size[p_x];
        
        if(rank[p_x] > rank[p_y]) {
            parent[p_y] = p_x;
            size[p_x]   += size[p_y];
            return this->size[p_x];
        } else if(rank[p_y] > rank[p_x]) {
            parent[p_x] = p_y;
            size[p_y]   += size[p_x];
            return this->size[p_y];
        } else {
            parent[p_x] = p_y;
            size[p_y]   += size[p_x];
            rank[p_y]++;
            return this->size[p_y];
        }
    }
    
    int getGroupSize(int x) {
        //first find the parent of x (which represents the group)
        int px = find(x);
        return size[px];
    }
    
};

class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result = 0;
        UnionFind uf(m, n);
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    result = max(result, link(i, j, grid, uf));
                }
            }
        }
        
        return result;
    }
    
    int link(int i, int j, vector<vector<int>>& grid, UnionFind& uf) {
        /*
            Below is a general way of findind index of an
            element of a 2-d matrix visualzied in a 1-d matrix
        */
        int index = i*n + j;
        
        int size  = uf.getGroupSize(index);
        
        auto isSafe = [&grid](int& x, int& y) {
            return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1;
        };
        
        for(vector<int> &dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];
            
            if(isSafe(x, y)) {
                size = max(size, uf.Union(index, x*n + y));
            }
        }
        return size;
        
    }
    
};