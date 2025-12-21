// //Leetcode 2359 . Find Closest Node to Given Two Nodes
// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

// You are also given two integers node1 and node2.

// Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

// Note that edges may contain cycles.

 

// Example 1:


// Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
// Output: 2
// Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
// The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
// Example 2:


// Input: edges = [1,2,-1], node1 = 0, node2 = 2
// Output: 2
// Explanation: The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
// The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.
 

// Constraints:

// n == edges.length
// 2 <= n <= 105
// -1 <= edges[i] < n
// edges[i] != i
// 0 <= node1, node2 < n

class Solution {
public:
    //simple dfs Traversal instead of storing node in vector store  their distance  from source node
    void dfs(vector<int>& edges , vector<int>& dist , vector<bool>& vis , int node)
    {
     int v =edges[node];
       
        if(v!=-1 && !vis[v])
        {
            vis[v]=true;
             dist[v]=dist[node]+1;
            dfs(edges , dist , vis , v);
        }
        
    }
    //Approach Calculate the dis of each node from node1 and node2 . 
    //At last pick the   node index having smallest distance
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n =edges.size();
        vector<int>dist1(n , INT_MAX);
        vector<int>dist2(n , INT_MAX);
        //dist to src node will be 0
        dist1[node1]=0;
        dist2[node2]=0;
        vector<bool> vis1(n , false);
        vector<bool>vis2( n , false);
        vis1[node1]=true;
        vis2[node2]=true;

        dfs(edges ,dist1 , vis1 ,  node1);
        dfs(edges , dist2 , vis2 , node2);
        //we got all dist from both src node1 , node2 
        //get the min index
        int minIndex=-1;
        int  minValue=INT_MAX;
        for(int i =0;i<n;i++)
            {
               int maxValueAtIndex=  max(dist1[i] , dist2[i]);
                if(maxValueAtIndex  <minValue)
                {
                    minValue=maxValueAtIndex;
                    minIndex=i;
                }
            }
        return minIndex;
        
        
        
    
        
    }
};