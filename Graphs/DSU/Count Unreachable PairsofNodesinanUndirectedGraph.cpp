// // Leetcode : 2316 . Count Unreachable Pairs of Nodes in an Undirected Graph
// You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

// Return the number of pairs of different nodes that are unreachable from each other.

 

// Example 1:


// Input: n = 3, edges = [[0,1],[0,2],[1,2]]
// Output: 0
// Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
// Example 2:


// Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
// Output: 14
// Explanation: There are 14 pairs of nodes that are unreachable from each other:
// [[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
// Therefore, we return 14.
 

// Constraints:

// 1 <= n <= 105
// 0 <= edges.length <= 2 * 105
// edges[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no repeated edges.


class Solution {
public:
//Step-1 With Help of dsu create components
//step-2 create hashmap  to store component(parent) and total size of that component
//step-3 traverse in hashmap and get ans = ans+size*(remaining-size)

    vector<int> parent;
    vector<int>rank;

    int  Find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=Find(parent[x]);
    }

    void Union(int x , int y)
    {
        int  x_parent= Find(x);
        int y_parent= Find(y);
        if(x_parent== y_parent)
        {
            return ;
        }
        if(x_parent!= y_parent)
        {
            if(rank[x_parent] > rank[y_parent])
            {
                 parent[y_parent]=x_parent;
            }
            else  if (rank[y_parent]> rank[x_parent])
            {
                parent[x_parent]=y_parent;
            }
            else{
                parent[x_parent]=y_parent;
                rank[y_parent]+=1;
            }
        }

    }

    long long countPairs(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        rank.resize(n);
        for(int i=0 ;i< n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }

        //union  nodes
        for(auto it: edges)
        {
            int u = it[0];
            int v= it[1];
            Union(u ,v);
        }
       unordered_map<int , int> mp;
        // Find parents and  update hasmap
        for(int i =0;i<n;i++)
        {
            int parent = Find(i);
            mp[parent]++;
        }

        //  get ans = ans+size*(remaining-size)
        long long result=0;
        long long remaining =n;
       
         for (auto it: mp)
         {
              int size =it.second;
              result+=size *(remaining-size);
              remaining =remaining-size;
         }
         return   result;


        
    }
};