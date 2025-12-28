// //Leetcode: 2360 .Longest Cycle in a Graph
// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

// Return the length of the longest cycle in the graph. If no cycle exists, return -1.

// A cycle is a path that starts and ends at the same node.

 

// Example 1:


// Input: edges = [3,3,4,2,3]
// Output: 3
// Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
// The length of this cycle is 3, so 3 is returned.
// Example 2:


// Input: edges = [2,-1,3,1]
// Output: -1
// Explanation: There are no cycles in this graph.
 

// Constraints:

// n == edges.length
// 2 <= n <= 105
// -1 <= edges[i] < n
// edges[i] != i

class Solution {
public:
    //Do DFS Traversal and to detect cycle in directed graph we need InRecusrison vector
    // mark it  true when travelling in same recursion call while comin out mark it as false.
    //for ex 1->2<-3
    //Have count vector to have count of node visited before visiting particular node and
    //update it using count[v] =count[u]+1;
    //at last return max value of count[v]-count[u]+1

    int  ans =-1;
    void dfsSolve(int node ,vector<int>& edges ,vector<bool> &visited  , vector<bool> &inRecursion ,  vector<int> &count )
    {
        visited[node]=true;
        inRecursion[node]=true;
        int v= edges[node];
        if(v!=-1 && !visited[v])
        {
            count[v]=count[node]+1;
         //   cout<<"count at "<<v<<":"<<count[v]<<endl;
            dfsSolve(v , edges , visited , inRecursion , count);
        }
        //already visited and in same Recurssion call
        else if(v!=-1 && visited[v] && inRecursion[v])
        {   
          //  cout<<"for "<<v<<endl;
            ans = max(ans , count[node]-count[v]+1);
           // cout<<"ans"<<ans<<endl;

        }
        inRecursion[node]=false;
    }
    int longestCycle(vector<int>& edges) {
        int n =edges.size();
        vector<bool> visited(n ,false);
        vector<bool> inRecursion(n  , false);
        vector<int> count(n ,1);

        for(int i =0;i< n;i++)
        {
            if(!visited[i])
            {
                dfsSolve(i , edges , visited , inRecursion , count);
            }
        }
        return ans;



        
        
    }
};