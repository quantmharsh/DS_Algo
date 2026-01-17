// //Leetcode: 2608 .Shortest Cycle in a Graph
// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1. The edges in the graph are represented by a given 2D integer array edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

// Return the length of the shortest cycle in the graph. If no cycle exists, return -1.

// A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.

 

// Example 1:


// Input: n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
// Output: 3
// Explanation: The cycle with the smallest length is : 0 -> 1 -> 2 -> 0 
// Example 2:


// Input: n = 4, edges = [[0,1],[0,2]]
// Output: -1
// Explanation: There are no cycles in this graph.
 

// Constraints:

// 2 <= n <= 1000
// 1 <= edges.length <= 1000
// edges[i].length == 2
// 0 <= ui, vi < n
// ui != vi
// There are no repeated edges.

class Solution {
public:
//solve using bfs since we need to find shortest cycle which is shortest distance
// ignore original edge between u and v and try to find if we can reach u to v without that edge
//if we are able to reach there then there is a cycle so return distance till that node +1
//at last store min value among all edges
    int findShortestCycle(int n, vector<vector<int>>& edges) {
          
         const  int INF=1<<30;
         int ans =INF;
        vector<vector<int>> adjList(n) ;
         for(auto it: edges)
         {
            int u =it[0];
            int v= it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
         }
         //Lambda function
         auto findShortestCycleUsingBfs =[&](int startNode  , int endNode ) ->int{
            
            //for each edge we will calculate distance and do bfs for each edge so declaring
            //all variables and queue here
           //  vector<int> distance(n , INF);
          vector<int> distance(n, INF);

            queue<int> q;
            q.push(startNode);
            
            distance[startNode]=0;
            
            while(!q.empty())
            {
                int node =q.front();
                q.pop();
                for (int v: adjList[node])
                {
                    //v should not be visited and there should be no direct edge
                    bool isExcluded =(v==endNode && node ==startNode) || (v==startNode && node ==endNode);
                    if(distance[v]!=INF || isExcluded)
                    {
                        continue;
                    }
                    else{
                        q.push(v);
                        distance[v]=distance[node]+1;
                    }

                }

            }
            return distance[endNode]+1;

            

         };
       

         for(auto it:edges)
         {
            int u=it[0];
            int v=it[1];
            cout<<"call for u and v"<<u<<":"<<v<<endl;
          ans =min(ans ,findShortestCycleUsingBfs(u , v));
         }

        return  ans< INF ?ans : -1;
         

         





        
        
    }
};