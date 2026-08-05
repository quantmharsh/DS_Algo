// //Leetcode:3310. Remove Methods From Project
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are maintaining a project that has n methods numbered from 0 to n - 1.

// You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi.

// There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.

// A group of methods can only be removed if no method outside the group invokes any methods within it.

// Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.

 

// Example 1:

// Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]

// Output: [0,1,2,3]

// Explanation:



// Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without removing anything.

// Example 2:

// Input: n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]

// Output: [3,4]

// Explanation:



// Methods 0, 1, and 2 are suspicious and they are not directly invoked by any other method. We can remove them.

// Example 3:

// Input: n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]

// Output: []

// Explanation:



// All methods are suspicious. We can remove them.

 

// Constraints:

// 1 <= n <= 105
// 0 <= k <= n - 1
// 0 <= invocations.length <= 2 * 105
// invocations[i] == [ai, bi]
// 0 <= ai, bi <= n - 1
// ai != bi
// invocations[i] != invocations[j]

class Solution {
public:
    //Approach: Using Kahns Algorithm BFS
    //Since we need to identify all nodes which are directly and indirectly  infected by k 
    //we will start traversal  from k and traverse to all its neighbours 
    //and while visiting mark  node as suspected and reduce its indegree by 1
    //we will also have a indegree of each node which we will calculate at beginning
    //after doing bfs traversal we will check  if node is suspected and its indegree >0 then 
    //there are other functions   which call this suspected node so we cant remove any node
    //in this case return all nodes in form of vector 
    // otherwise remove all nodes which are marked suspected true
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        unordered_map<int , vector<int>> mp;
        queue<int>q;
        vector<bool> suspecious(n , false);
        vector<int>indegree(n,0);
        vector<int>ans;
        for(auto it: invocations)
        {
            int u =it[0];
            int v=it[1];
            mp[u].push_back(v);
            indegree[v]++;
        

        }
        //starting from k node 
        q.push(k);
        suspecious[k]=true;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto it: mp[curr])
            {
                indegree[it]--;
                if(!suspecious[it])
                {
                    q.push(it);
                    suspecious[it]=true;
                }
            }
        }
        bool cantRemove=false;
        for(int i =0;i<n;i++)
        {
            if(suspecious[i] && indegree[i]>0)
            {
                cantRemove=true;
                break;
            }
            if(!suspecious[i])
            {
             ans.push_back(i);
            }
            
        }
        vector<int> nodes;
        for(int i =0;i<n;i++)
        {
            nodes.push_back(i);
        }

        return cantRemove? nodes: ans;





        
    }
};