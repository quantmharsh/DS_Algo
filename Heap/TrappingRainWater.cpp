// //Leetcode:407. Trapping Rain Water II
// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 

// Example 1:


// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// Output: 4
// Explanation: After the rain, water is trapped between the blocks.
// We have two small ponds 1 and 3 units trapped.
// The total volume of water trapped is 4.
// Example 2:


// Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
// Output: 10
 

// Constraints:

// m == heightMap.length
// n == heightMap[i].length
// 1 <= m, n <= 200
// 0 <= heightMap[i][j] <= 2 * 104

class Solution {
public:
    typedef pair<int ,pair<int ,int>>HI;
    vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        //Priority Queue min heap to get min height first
        priority_queue<HI ,vector<HI>, greater<>> boundaryCells;
        int m= heightMap.size();
        int n= heightMap[0].size();
        vector<vector<bool>> visited(m , vector<bool>(n ,false));
        //store all  boundary rows
        for(int r=0;r<m;r++)
        {
            for(int c:{0 , n-1})
            {
                boundaryCells.push({heightMap[r][c], {r,c})};
                //mark at visited
                visited[r][c]=true;

            }
        }
          //store all  boundary cols
   for (int c = 0; c < n; ++c) {
            for (int r : {0, m - 1}) { //0 : top most boundary, rows-1 bottom most boundary
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        //travere through priority queue
        int water=0;
        while(!boundaryCells.empty())
        {
            HI hi=boundaryCells.top();
            boundaryCells.pop();
            int height=hi.first;
            int i=hi.second.first;
            int j=hi.second.second;
            //traverse all four directions

            for(vector<int>& dir:directions)
            {
                int _i=i+dir[0];
                int _j=j+dir[1];


                //check whether index is valid or not
                if(_i>=0 && _i<m && _j>=0 && _j<n && !visited[_i][_j] )
                {
                    water+=max(0,height-heightMap[_i][_j]);
                    boundaryCells.push(max({height , heightMap[_i][_j]),{_i , _j}});
                    visited[_i][_j]=true;
                }
            }


        }
        return water;



        
    }
};