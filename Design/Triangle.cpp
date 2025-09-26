// //Leetcode: 120 Triangle
// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10
 

// Constraints:

// 1 <= triangle.length <= 200
// triangle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -104 <= triangle[i][j] <= 104
 

// Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?

//T.C : O(n^2)
//S.C : O(1)
//Bottom-Up Optimized step manipulating input
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n =triangle.size();
        for(int row=1;row<n;row++)
        {
            for(int col=0;col<=row;col++)
            {
                //min bound to not get negative index
                int prev_row_up = triangle[row-1][min(col , (int)triangle[row-1].size()-1)];
                //max bound
                int prev_row_left=triangle[row-1][max(col-1 ,0)];
                triangle[row][col]+=min(prev_row_up , prev_row_left);
            }
        }
        return *min_element(begin(triangle[n-1]) , end(triangle[n-1]));
    }
};