// //Leetcode: 812 Largest Triangle Area
// Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:


// Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
// Output: 2.00000
// Explanation: The five points are shown in the above figure. The red triangle is the largest.
// Example 2:

// Input: points = [[1,0],[0,0],[0,1]]
// Output: 0.50000
 

// Constraints:

// 3 <= points.length <= 50
// -50 <= xi, yi <= 50
// All the given points are unique.

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        
        double area=0;
        int n =points.size();
        for(int i =0;i<n;i++)
        {
            for(int j =i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    double x1=points[i][0];
                    double y1=points[i][1];
                    double  x2= points[j][0];
                    double y2=points[j][1];
                    double x3=points[k][0];
                    double y3=points[k][1];
                    double  shoelace=0.5 *abs(x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2));
                    area=max(area , shoelace); 
                }
            }
        }
        return area;
    }
};