// //leetcode:1401. Circle and Rectangle Overlapping
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

// Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.

 

// Example 1:


// Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
// Output: true
// Explanation: Circle and rectangle share the point (1,0).
// Example 2:

// Input: radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
// Output: false
// Example 3:


// Input: radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
// Output: true
 

// Constraints:

// 1 <= radius <= 2000
// -104 <= xCenter, yCenter <= 104
// -104 <= x1 < x2 <= 104
// -104 <= y1 < y2 <= 104
class Solution {
public:
    //Approach: We needs to find the  closest xi and yi between circle and rectangle
    // if x2<xc then closest xi=x2
    //if x1>xc then closet xi=x1 else xi=xc 
    //similarly find yi 
    //then find distnace . if d<=r then return true else false
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
        int xi=0;
        int yi=0;
        if(x2<xCenter)
        {
            xi=x2;
        }
        else if( x1> xCenter)
        {
            xi=x1;
        }
        else{
            xi=xCenter;
        }

         if(y2<yCenter)
        {
            yi=y2;
        }
        else if( y1> yCenter)
        {
            yi=y1;
        }
        else{
            yi=yCenter;
        }

        return sqrt((xCenter-xi)*(xCenter-xi) +(yCenter-yi)*(yCenter-yi)) <=radius;

    }
};