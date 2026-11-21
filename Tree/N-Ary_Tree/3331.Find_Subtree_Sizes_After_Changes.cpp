// //Leetcode:3331. Find Subtree Sizes After Changes
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a tree rooted at node 0 that consists of n nodes numbered from 0 to n - 1. The tree is represented by an array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

// You are also given a string s of length n, where s[i] is the character assigned to node i.

// We make the following changes on the tree one time simultaneously for all nodes x from 1 to n - 1:

// Find the closest node y to node x such that y is an ancestor of x, and s[x] == s[y].
// If node y does not exist, do nothing.
// Otherwise, remove the edge between x and its current parent and make node y the new parent of x by adding an edge between them.
// Return an array answer of size n where answer[i] is the size of the subtree rooted at node i in the final tree.

 

// Example 1:

// Input: parent = [-1,0,0,1,1,1], s = "abaabc"

// Output: [6,3,1,1,1,1]

// Explanation:


// The parent of node 3 will change from node 1 to node 0.

// Example 2:

// Input: parent = [-1,0,4,0,1], s = "abbba"

// Output: [5,2,1,1,1]

// Explanation:


// The following changes will happen at the same time:

// The parent of node 4 will change from node 1 to node 0.
// The parent of node 2 will change from node 4 to node 1.
 

// Constraints:

// n == parent.length == s.length
// 1 <= n <= 105
// 0 <= parent[i] <= n - 1 for all i >= 1.
// parent[0] == -1
// parent represents a valid tree.
// s consists only of lowercase English letters.
class Solution {
public: 
    //Approach: DFS Recursion
    // TC: O(N)
    //SC: O(N)
    //create a track of when lasttime we had node which have same character as currnode
    //so that we can  change parent of currentnode to correct nearestAncestor node
    //Then update last to currnode . because for currnode its child willl treate currnode at nearest ancestor if they ahve same char
    //Do recursive call for dfs
    //when returning back . then  undo last to nearestancesto
    //also in result[nearestancestor] add result[currnode]

    //create adj list to store child
    unordered_map<int , vector<int>> adjList;
    vector<int> last;
    vector<int>result;
    void dfsSolve(int currNode , string& s , vector<int>& parent)
    {
        //take char at currNode
        int ch=s[currNode]-'a';    
        //find the nearestAncestor which have same ch . 
        int nearestAncestor =last[ch];
 
        //for child of currNode update last to currnode. means lastime when we saw char ch
        //it was as currnode
        last[ch]=currNode;
        //traverse over all child of currnode
        for(auto it: adjList[currNode])
        {
            dfsSolve(it , s , parent);
        }
        //came back from recursion 
        //updare last seen to nearestancestor
        last[ch]=nearestAncestor;
        //update currnodes parent to newparent which is nearestancestor
        if(currNode !=0 )
        {
            int newParent =parent[currNode];
            if(nearestAncestor!=-1)
            { 
           
            newParent =nearestAncestor;
            }  
             parent[currNode]= newParent;
             result[newParent]+=result[currNode];
            

        }


    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n =parent.size();
       
        for(int i=1;i<n;i++)
        {
            int u =parent[i];
            int v=i;
            adjList[u].push_back(v);
        }
        result.assign(n ,1);
        last.assign(26 ,-1);
        dfsSolve(0 ,s,parent );
        return result;
        
    }
};