// //Leetcode:3534. Path Existence Queries in a Graph II
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.

// You are also given an integer array nums of length n and an integer maxDiff.

// An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).

// You are also given a 2D integer array queries. For each queries[i] = [ui, vi], find the minimum distance between nodes ui and vi. If no path exists between the two nodes, return -1 for that query.

// Return an array answer, where answer[i] is the result of the ith query.

// Note: The edges between the nodes are unweighted.

 

// Example 1:

// Input: n = 5, nums = [1,8,3,4,2], maxDiff = 3, queries = [[0,3],[2,4]]

// Output: [1,1]

// Explanation:

// The resulting graph is:



// Query	Shortest Path	Minimum Distance
// [0, 3]	0 → 3	1
// [2, 4]	2 → 4	1
// Thus, the output is [1, 1].

// Example 2:

// Input: n = 5, nums = [5,3,1,9,10], maxDiff = 2, queries = [[0,1],[0,2],[2,3],[4,3]]

// Output: [1,2,-1,1]

// Explanation:

// The resulting graph is:



// Query	Shortest Path	Minimum Distance
// [0, 1]	0 → 1	1
// [0, 2]	0 → 1 → 2	2
// [2, 3]	None	-1
// [4, 3]	3 → 4	1
// Thus, the output is [1, 2, -1, 1].

// Example 3:

// Input: n = 3, nums = [3,6,1], maxDiff = 1, queries = [[0,0],[0,1],[1,2]]

// Output: [0,-1,-1]

// Explanation:

// There are no edges between any two nodes because:

// Nodes 0 and 1: |nums[0] - nums[1]| = |3 - 6| = 3 > 1
// Nodes 0 and 2: |nums[0] - nums[2]| = |3 - 1| = 2 > 1
// Nodes 1 and 2: |nums[1] - nums[2]| = |6 - 1| = 5 > 1
// Thus, no node can reach any other node, and the output is [0, -1, -1].

 

// Constraints:

// 1 <= n == nums.length <= 105
// 0 <= nums[i] <= 105
// 0 <= maxDiff <= 105
// 1 <= queries.length <= 105
// queries[i] == [ui, vi]
// 0 <= ui, vi < n


class Solution {
public:
    //Approach:  Binary Lifting Concept
    //This question can be solved using BL concept
    //while building ancestortable we dont need to store parent  here we need to store the
    //node at which we can reach when doing  jump .we can jump until  target <maxdiff+node value
    //we need to create a 2d integer array and store ith index and value at ith index [5,0][3,1]
    //then sort the array on basis of value 
    //then have  int nodetoindex array where we will store the original index of node
    //build a ancestor table 
    //traverse over queries and get u and v 
    //look into our nodetoindex aray and get index a and b
    //then if a> b  swap both  because we want to traverse in single direction only .and start traversing on ancestor table
    //start with maxjump means j=col then check if at[curr][j]<b then curr=at[curr][j] and jum=jump+1
    //then after loop traversal check if at[curr][0]<=b if then res.pushjump+1 else -1

    int rows ;
    int cols ;
    vector<vector<int>> ancestorTable;

    int calculateFarthestNode(  vector<pair<int , int>>& arr ,int target,int n)
    {
        int l=0;
        int r=n-1;
       int result=0;
        while(l<=r)
        {
         int mid=l+(r-l)/2;
         if(arr[mid].first > target)
         {
            r=mid-1;
         }
         else
         {
            l=mid+1;
            result=mid;
         }
        }
        return result;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        rows= n;
        cols=log2(n)+1;
        ancestorTable.resize(n ,vector<int>(cols ,0));
        vector<pair<int , int>> arr(n);
        vector<int>nodeToIndex(n);
        //create arr
        for(int i =0;i<n;i++)
        {
            arr[i].first=nums[i];
            arr[i].second=i;

        }
        sort(arr.begin() ,arr.end());
        for(int i =0;i<n;i++)
        {
            int node= arr[i].second;
            nodeToIndex[node]=i;
        }
       
        //Build Ancestor table for 0th column
        //it stores farthest node that we can reach in 1 jump
        for(int node=0;node<n;node++)
        {
            ancestorTable[node][0]=calculateFarthestNode(arr , arr[node].first+maxDiff , n);
        }

        for(int j =1;j<cols;j++)
        {
            for(int node=0;node<n;node++)
            {
                ancestorTable[node][j]=ancestorTable[ancestorTable[node][j-1]][j-1];
            }
        }
        vector<int>result;
        for(auto it: queries)
        {
            int u=it[0];
            int v=it[1];
            int a= nodeToIndex[u];
            int b=nodeToIndex[v];
            int jump=0;

            if(a==b)
            {
                result.push_back(0);
                continue;
            }
            if(a>b)
            {
                swap(a,b);
            }

            int curr=a;
            for(int j=cols-1;j>=0;j--)
            {
                if(ancestorTable[curr][j]<b)
                {
                    curr=ancestorTable[curr][j];
                    jump+= (1<<j);
                }
            }

            if(ancestorTable[curr][0]>=b)
            {
                result.push_back(jump+1);
            }
            else
            {
                result.push_back(-1);
            }

        }
        return result;


        



        
    }
};