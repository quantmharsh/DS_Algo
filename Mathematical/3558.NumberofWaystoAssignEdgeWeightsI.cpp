// //Leetcode:3558. Number of Ways to Assign Edge Weights I
// There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.

// Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.

// The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.

// Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd.

// Since the answer may be large, return it modulo 109 + 7.

// Note: Ignore all edges not in the path from node 1 to x.

 

// Example 1:



// Input: edges = [[1,2]]

// Output: 1

// Explanation:

// The path from Node 1 to Node 2 consists of one edge (1 → 2).
// Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
// Example 2:



// Input: edges = [[1,2],[1,3],[3,4],[3,5]]

// Output: 2

// Explanation:

// The maximum depth is 2, with nodes 4 and 5 at the same depth. Either node can be selected for processing.
// For example, the path from Node 1 to Node 4 consists of two edges (1 → 3 and 3 → 4).
// Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.
 

// Constraints:

// 2 <= n <= 105
// edges.length == n - 1
// edges[i] == [ui, vi]
// 1 <= ui, vi <= n
// edges represents a valid tree.
class Solution {
public:
    //Approach: Using  DFS & Binary Exponentiation
    //Find max Depth using DFS then 
    //then total combination which exists will be 2^(d-1)
     static constexpr long long MOD = 1e9 + 7;
     //It calculates large exponential power in TC O(log n);
     long long  binaryExponentiation(int base , int k)
     {
        //if power is  0 return 1 . for ex: 2^0 , 3^0
        if(k==0)
        {
            return 1;
        }
        long long half=binaryExponentiation(base , k/2);
        long long result= (half*half)%MOD;
        if(k%2==1)
        {
            result=(result*base)%MOD;
        }
        return result;
     }
    int getDepthUsingDfs(unordered_map<int , vector<int>>& adjList , int parent , int node)
    {
        int depth=0;
        for(auto it:adjList[node])
        {
            if(it==parent)
            {   cout<<"Parent"<<parent;
                continue;
            }
            depth =max(depth , getDepthUsingDfs(adjList , node , it)+1);
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {

        unordered_map<int , vector<int>> adjList;
        //Build AdjList
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        //calculate max Depth
        int depth =getDepthUsingDfs(adjList ,0, 1);
        //calculate total possible way to assign weight so its sum is odd
        return  binaryExponentiation(2,depth-1);
        
    }
};