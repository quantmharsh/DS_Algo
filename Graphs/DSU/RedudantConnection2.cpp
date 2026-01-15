// //Leetcode: 685 . Redudant connection 2 (Hard)
// In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

// The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.

// The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.

// Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

 

// Example 1:


// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]
// Example 2:


// Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
// Output: [4,1]
 

// Constraints:

// n == edges.length
// 3 <= n <= 1000
// edges[i].length == 2
// 1 <= ui, vi <= n
// ui != vi

class Solution {
public:

    //solve  using DSU +indegree
    //if any of the node have indegree 2 push that in duplicateedge array
    //try to remove  2nd edge which appears and then try to to dsu if no cycle then return that edge
    //else return another edge
    //if indegee is not 2 for any of the node then find the edge which creates cycle nad return that edge (redudant connection logic)

    vector<int> parent;
    vector<int> rank;
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return  find(parent[x]);
    }

    void unionByRank(int x   , int y)
    {
        int x_parent= find(x);
        int y_parent = find(y);
        if(rank[x_parent]>rank[y_parent])
        {
            parent[y_parent]=x_parent;
        }
        else if(rank[y_parent]> rank[x_parent])
        {
            parent[x_parent]=y_parent;
        }
        else{
           parent[y_parent]=x_parent;
           rank[x_parent]++;
        
        }
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n =edges.size();
        vector<int> indegree(n+1 , 0);
        vector<int> dup;
        parent.resize(n+1 , 0);
        rank.resize(n+1 , 0);
        for(int i =0;i<=n;i++)
        {
            parent[i]=i;
        }

        for(auto it: edges)
        {
            int u=it[0];
            int v= it[1];
            indegree[v]++;
            cout<<"indegree of "<<v<<"="<<indegree[v]<<endl;
        }
        for(int i =0;i<n;i++)
        {
            int v =edges[i][1];
            if(indegree[v]==2)
            {
                dup.push_back(i);
                cout<<"for v="<<v<<endl;
                cout<<"pushed i="<<i<<endl;
            }

        }

        if(!dup.empty())
        {
            cout<<"dup is not empty"<<endl;
            for(int i=0;i<n;i++)
            {       
                // cout<<"it[1]="<<it[1]<<endl;
                // cout<<"dup[1]"<<dup[1]<<endl;
                // cout<<"dup[0]"<<dup[0]<<endl;
                if(i==dup[1])
                {
                    continue;
                }
                int u =edges[i][0];
                int v= edges[i][1];
                if(find(u)==find(v))
                {
                    return  edges[dup[0]];
                }
                unionByRank(u , v);

            }
            return edges[dup[1]];
        }


           for(auto it:edges)
           {
            int u =it[0];
            int v=it[1];
            if(find(u)==find(v))
            {
                return  it;
            }

            unionByRank( u ,v);

            
           }
        return {};

        
    }
};