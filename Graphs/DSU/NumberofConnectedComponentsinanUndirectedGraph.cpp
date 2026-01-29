// // Neetcode: Number of Connected Components in an Undirected Graph
// You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [aᵢ, bᵢ] indicates that there is an edge between aᵢ and bᵢ in the graph.

// Return the number of connected components in the graph.

// Example 1:



// Input:
// n = 5, edges = [[0,1],[1,2],[3,4]]

// Output: 2
// Example 2:



// Input:
// n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]

// Output: 1
// Constraints:

// 1 <= n <= 2000
// 1 <= edges.length <= 5000
// edges[i].length == 2
// 0 <= aᵢ <= bᵢ < n
// aᵢ != bᵢ
// There are no repeated edge

class Solution {
public:

    vector<int>parent;
    vector<int>rank;

    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return   find(parent[x]);
    }

    void unionByRank( int x  , int y)
    {
        int x_parent =find(x);
        int y_parent = find(y);
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
            rank[x_parent]+=1;
        }

    }


    int countComponents(int n, vector<vector<int>>& edges) {

        parent.resize(n ,0);
        rank.resize(n , 0);
        for(int i =0;i<n;i++)
        {
            parent[i]=i;
        }
        for(auto it:edges)
        {
            int u =it[0];
            int v=it[1];
            unionByRank(u  , v);

        }

        int cnt=0;
        for(int i =0;i<n;i++)

        {
            if(find(i)==i)
            {
                cnt++;
            }
        }
        return  cnt;

    }
};

