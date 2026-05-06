// //Leetcode: 1722. Minimize Hamming Distance After Swap Operations
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.

// The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).

// Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.

 

// Example 1:

// Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
// Output: 1
// Explanation: source can be transformed the following way:
// - Swap indices 0 and 1: source = [2,1,3,4]
// - Swap indices 2 and 3: source = [2,1,4,3]
// The Hamming distance of source and target is 1 as they differ in 1 position: index 3.
// Example 2:

// Input: source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
// Output: 2
// Explanation: There are no allowed swaps.
// The Hamming distance of source and target is 2 as they differ in 2 positions: index 1 and index 2.
// Example 3:

// Input: source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
// Output: 0
 

// Constraints:

// n == source.length == target.length
// 1 <= n <= 105
// 1 <= source[i], target[i] <= 105
// 0 <= allowedSwaps.length <= 105
// allowedSwaps[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi


class Solution {
public: 

    //Approach: Using DSU
    //TC: O(N)
    //SC:O(N)
    //since we can swap any element to any  which is in same group so thats hint us that dsu can be used and grouping concept.
    // using unordered map which stores in which group index i is there and also store source[index] and its total count in that group
    //we are storing count because it is possible that target can  have same value at multiple places
    //for ex  in our source we have 2  1 time and in target  we have 2 2 times and all in same group.So that will create problem we cant keep same no, at 2 places. [2,3,1] [1,2,2] [[0,2],[1,2]]
    //Do DSU and add in same group by going through allowed steps
    //create unordered map
    //initialize map by finding parent  of index i and store source[i] and increase  its count by 1
    //again loop take index i  and find its parent  and then in target array check which num is at index i target[i]
    //if groupfreq[index][target[i]] having count >1  then reduce it count
    //else increase count of ans++

    vector<int>parent;
    vector<int>rank;
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return find(parent[x]);
    }
    void unionByRank(int  x, int y)
    {
        int parent_x=find(x);
        int parent_y= find(y);
        if(rank[parent_x]>rank[parent_y])
        {
            parent[parent_y]=parent_x;

        }
       else  if(rank[parent_y]>rank[parent_x])
        {
            parent[parent_x]=parent_y;
        }
        else{
            parent[parent_y]=parent_x;
            rank[parent_x]++;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n =source.size();
        unordered_map<int , unordered_map<int , int>> mp;
        int ans=0;
        parent.resize(n);
        rank.resize(n , 0);
        for(int i =0; i<n;i++)
        {
            parent[i]=i;
        }

        for(auto it: allowedSwaps)
        {
            int u =it[0];
            int v=it[1];
            unionByRank(u , v);
        }

        for(int i =0;i<n;i++)
        {
              
            int parent= find(i);
            mp[parent][source[i]]++;  

        }

        for(int i =0;i<n;i++)
        {
            int parent=find(i);
            if(mp[parent][target[i]]>0){
                mp[parent][target[i]]--;
            }
            else{
                ans++;
            }
        }
        return ans;
        
        
    }
};