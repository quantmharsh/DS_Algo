// //Leetcode:1861. Rotating the Box
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:

// A stone '#'
// A stationary obstacle '*'
// Empty '.'
// The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

// It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.

// Return an n x m matrix representing the box after the rotation described above.

 

// Example 1:



// Input: boxGrid = [["#",".","#"]]
// Output: [["."],
//          ["#"],
//          ["#"]]
// Example 2:



// Input: boxGrid = [["#",".","*","."],
//               ["#","#","*","."]]
// Output: [["#","."],
//          ["#","#"],
//          ["*","*"],
//          [".","."]]
// Example 3:



// Input: boxGrid = [["#","#","*",".","*","."],
//               ["#","#","#","*",".","."],
//               ["#","#","#",".","#","."]]
// Output: [[".","#","#"],
//          [".","#","#"],
//          ["#","#","*"],
//          ["#","*","."],
//          ["#",".","*"],
//          ["#",".","."]]
 

// Constraints:

// m == boxGrid.length
// n == boxGrid[i].length
// 1 <= m, n <= 500
// boxGrid[i][j] is either '#', '*', or '.'.

class Solution {
public:

    //Approach:Transpose and  reverse the matrix
    //Then add gravity effect into it. To add this effect we need to traverse every column starting from last row
    //we will have a pointer which will point to the first space that we found from bottom.
    //then if we found stone then  replace it with space and at index where we spot firstspace at that index  we will have '#' and reduce spaceindex by 1
    //if we found blocker then reset spaceindex to blocker-1 index. because its the max down where e can go
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int m=boxGrid.size();
        int n =boxGrid[0].size();
        vector<vector<char>> ans(n ,vector<char>(m));

        //Transpose matrix
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)

            {   
                ans[i][j]= boxGrid[j][i];
            }

        }
        //Reverse every row
        for(int i =0;i<n;i++)
        {
            reverse(ans[i].begin() , ans[i].end());
        }

            //Apply Gravitation effect

            for(int i =0;i<m;i++)
            {
                int lastSpaceIndex=n-1;
                for(int j =n-1;j>=0;j--)
                {
                    //if we got a stone
                    if(ans[j][i]=='#')
                       { ans[j][i]='.';
                       ans[lastSpaceIndex][i]='#';
                       lastSpaceIndex--;
                    
                    
                    }
                    else if (ans[j][i]=='*')
                    {
                        lastSpaceIndex=j-1;
                    }
                }
            }
        return  ans;


        
        
    }
}; 