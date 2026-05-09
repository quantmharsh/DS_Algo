// //Leetcode:1914. Cyclically Rotating a Grid
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.

// The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:



// A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:


// Return the matrix after applying k cyclic rotations to it.

 

// Example 1:


// Input: grid = [[40,10],[30,20]], k = 1
// Output: [[10,20],[40,30]]
// Explanation: The figures above represent the grid at every state.
// Example 2:


// Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
// Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
// Explanation: The figures above represent the grid at every state.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 2 <= m, n <= 50
// Both m and n are even integers.
// 1 <= grid[i][j] <= 5000
// 1 <= k <= 109

class Solution {
public:

    //Approac:total no. of layers that we will be min of row ,col divided by 2
    //then we will have for loop for each layer
    //and inside that we will travers all 4 directions and take care os edge indexes.count it only 1 time
    //then since here we are traversing in anticlockwise we will create a singgel array list
    //then we need to rotate it to right elements by k steps.
    //and our k will be  modulo of our nums array length k=k%len;
    //Then we need to store rotated values of this layer again intto grid in same order the way we extrated and stored it

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n =grid.size();
        int m=grid[0].size();
        
    int layers=min(n ,m)/2;
    for(int layer =0;layer<layers ;layer++)
    {
        int top =layer;
        int left=layer;
        int bottom =n-layer-1;
        int right=m-layer-1;
        vector<int>nums;
        //Traverse top
        //right to left
        for(int i =right;i>=left;i--)
        {
            nums.push_back(grid[top][i]);
        }
        //Traverse left 
        //top to bottom
        for(int i =top+1;i<=bottom;i++)
        {
            nums.push_back(grid[i][left]);
        }

        //Traverse bottom
        //left to right
        for(int i =left+1;i<=right;i++)
        {
            nums.push_back(grid[bottom][i]);
        }

        //Traverse right
        //bottom to top 
        for(int i =bottom-1;i>top;i-- )
        {
            nums.push_back(grid[i][right]);
        }

        int len=nums.size();
     int   new_k=k%len;

        rotate(nums.rbegin() ,nums.rbegin()+new_k, nums.rend());

        int index=0;
        //right to left
        for(int i =right;i>=left;i--)
        {
            grid[top][i]=nums[index++];
        }
        //Traverse left 
        //top to bottom
        for(int i =top+1;i<=bottom;i++)
        {
            grid[i][left]=nums[index++];
        }

        //Traverse bottom
        //left to right
        for(int i =left+1;i<=right;i++)
        {
            grid[bottom][i]=nums[index++];
        }

        //Traverse right
        //bottom to top 
        for(int i =bottom-1;i>top;i-- )
        {
            grid[i][right]=nums[index++];
        }



    }
    return grid;
    
        
    }
};