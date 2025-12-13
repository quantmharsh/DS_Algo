// //Leetcode 886 .Possible Bipartition
// We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

// Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

// Example 1:

// Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: The first group has [1,4], and the second group has [2,3].
// Example 2:

// Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
// Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
 

// Constraints:

// 1 <= n <= 2000
// 0 <= dislikes.length <= 104
// dislikes[i].length == 2
// 1 <= ai < bi <= n
// All the pairs of dislikes are unique.


class Solution {
public:
    bool  CheckBipartitionUsingDfs(int node , int  group ,unordered_map<int,vector<int>> &adjList ,  vector<int>&vis)
    {
        vis[node]=group;
        for(auto &it:adjList[node])
        {
            if(vis[it]==group)
            {
                return false;
            }
            if(vis[it]==-1)
            {
                 if(CheckBipartitionUsingDfs(it , !group , adjList , vis)==false)return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adjList(n+1);
        vector<int>vis(n+1 ,-1);
   
        
        for(auto &it: dislikes)
        {
            int u=it[0];
            int v= it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
       
        //Traverse All components 
        for(int i =1;i<=n;i++)
        {
            if(vis[i]==-1)
            {
                 if(CheckBipartitionUsingDfs(i , 1 , adjList , vis)==false)return false;
            }
        }
        return true;
    }
};