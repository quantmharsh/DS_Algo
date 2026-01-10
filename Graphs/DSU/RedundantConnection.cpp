// //Leetcode: 684 . Redundant Connection
// Medium
// Topics
// premium lock icon
// Companies
// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

// Example 1:


// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]
// Example 2:


// Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output: [1,4]
 

// Constraints:

// n == edges.length
// 3 <= n <= 1000
// edges[i].length == 2
// 1 <= ai < bi <= edges.length
// ai != bi
// There are no repeated edges.
// The given graph is connected.


class Solution {
public:
    //will be solving using DSU  
    //Do simple dsu just check if parent of both u and v are same then return that edge
    vector<int> parent;
    vector<int>rank;
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
        int x_parent= find(x);
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
            rank[y_parent]++;

        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int  n =edges.size();

        parent.resize( n+1 ,0);
        rank.resize( n+1 ,1);
        for(int i =1;i<=n;i++)
        {
            //
            parent[i]=i;
        }



        for(auto it: edges)
        {
            int u =it[0];
            int v=it[1];
            if(find(u)==find(v))
            {
                return it;
            }
            unionByRank(u , v);
        }

        return {};


        
    }
};