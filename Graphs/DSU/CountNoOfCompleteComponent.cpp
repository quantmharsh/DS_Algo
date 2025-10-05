// Leetcode 2685. Count the Number of Complete Components

// You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

// Return the number of complete connected components of the graph.

// A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

// A connected component is said to be complete if there exists an edge between every pair of its vertices.

 

// Example 1:



// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
// Output: 3
// Explanation: From the picture above, one can see that all of the components of this graph are complete.
// Example 2:



// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
// Output: 1
// Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
 

// Constraints:

// 1 <= n <= 50
// 0 <= edges.length <= n * (n - 1) / 2
// edges[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no repeated edges.

class Solution {
public:
    //Approach Will be Using DSU( Union By Size)
    //traverse through all edges and union them
    //create a map to store count of edges for each root . find root of u and increment mp[root]++
    //traverse again from i=0 to n and get the vertices count ,edge  of each root  . if i == find(i).which is the size of that root . and calculate  v*(v-1)/2==e  if true result++;

    vector<int>parent ;
    vector<int>size;
    int Find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=Find(parent[x]);
    }
    void Union(int x , int y)
    {
        int x_parent = Find(x);
        int y_parent= Find(y);
        if(x_parent==y_parent)
        {
            return;
        }
        if(size[x_parent]>size[y_parent])
        {
            parent[y_parent]=x_parent;
            size[x_parent]+=size[y_parent];
        }
        else if (size[y_parent]>size[x_parent])
        {
            parent[x_parent]=y_parent;
            size[y_parent]+=size[x_parent];
        }
        else{
             parent[y_parent]=x_parent;
            size[x_parent]+=size[y_parent];
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n);
        for(int i =0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
        unordered_map<int , int> mp;

        for(auto &it : edges)
        {
            int u = it[0];
            int v= it[1];
            Union(u , v);
        }

        //traverse through each edge and store  vertices count for each root
        for(auto &it: edges)
        {
            int u =it[0];
            int v=it[1];
            int root = Find(u);
            mp[root]++;
        }
        int result=0;
        //traverse  all n nodes 
        for(int i =0;i<n;i++)
        {
            if(i==Find(i))
            {
                int v=size[i];
                int e=mp[i];
                if((v*(v-1))/2 ==e)
                {
                    result++;
                }

            }
        }
        return result;
        
    }
};