// //Leetcode: 2196. Create Binary Tree From Descriptions
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

// If isLefti == 1, then childi is the left child of parenti.
// If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.

// The test cases will be generated such that the binary tree is valid.

 

// Example 1:


// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
// Explanation: The root node is the node with value 50 since it has no parent.
// The resulting binary tree is shown in the diagram.
// Example 2:


// Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
// Output: [1,2,null,null,3,4]
// Explanation: The root node is the node with value 1 since it has no parent.
// The resulting binary tree is shown in the diagram.
 

// Constraints:

// 1 <= descriptions.length <= 104
// descriptions[i].length == 3
// 1 <= parenti, childi <= 105
// 0 <= isLefti <= 1
// The binary tree described by descriptions is valid.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//Approach: Using Set and map 
// create a map of int , treenode* to map description to tree 
//create a set to store  all child  nodes.
//iterate over set and try to find parent if parent doesnt exists return that parent it will be root 
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int , TreeNode*> mp;
        unordered_set<int>  childSet;
        for(vector<int>&  it: descriptions)
        {
          
            int parent=it[0];
            int child=it[1];
            int isLeft=it[2];

            //check if parent exists if not then create new parent
            if(mp.find(parent)==mp.end())
            {
                mp[parent]= new TreeNode(parent);
            }

            //check if child exists . if not create new child
            if(mp.find(child)==mp.end())
            {
                mp[child]=new TreeNode(child);
            }

            //attach child to left or right
            if(isLeft==1)
            {
                mp[parent]->left=mp[child];
            }
            else{
                mp[parent]->right=mp[child];
            }

            //insert only child into set not parent
            childSet.insert(child);
        }
        

        //Find root of a tree. iterate over description if we are unable to find parent then thats root
        for(vector<int>& it: descriptions)
        {
            int parent=it[0];
            if(childSet.find(parent)==childSet.end())
            {
                return mp[parent];
            }
        }
        return NULL;
        
    }
};