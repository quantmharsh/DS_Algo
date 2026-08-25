// //Leetcode:1386. Cinema Seat Allocation
// A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.

// You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.

// A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:

// seats 2, 3, 4, 5

// seats 4, 5, 6, 7
// seats 6, 7, 8, 9
// A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.

// Return an integer denoting the maximum number of four-person groups that can be assigned.

 

// Example 1:



// Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
// Output: 4
// Explanation: The figure above shows an optimal allocation of four groups. Seats marked in blue are already reserved, and each set of four contiguous seats marked in orange is assigned to one group.
// Example 2:

// Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
// Output: 2
// Example 3:

// Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
// Output: 4
 

// Constraints:

// 1 <= n <= 109
// 1 <= reservedSeats.length <= min(10 * n, 104)
// reservedSeats[i] == [rowi, seati]
// 1 <= rowi <= n
// 1 <= seati <= 10
// All reservedSeats[i] are distinct.

class Solution {
public:
    //Approach: Using Bit Masking (Bit Manipulation)
    //find the mask of each row and store it in map
    //for finding mask of each row traverse  over reservedSeats .extract row and seat number
    //then do mp[row]|=1<<seatNumber
    //map will  have row and its masked as a value
    //then  find the mask for  Case A , Case B and Case C 
    //in result add  2* n0. of rows which dont have any seat booked (A and C can come together so doing 2*)
    //now traverse over map and for row present there .take its maskvalue
    //and do AND operation with all cases 1 by 1 .
    //if CASE A==0 and CASE C ==0 then in resukt +2 
    //if any one of case is true then result+1
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int  ,int> mp;
        for(auto it: reservedSeats)
        {
            int row=it[0];
            int seat=it[1];
            mp[row] |=(1<<seat);
        }

        int maskA=(1<<2)|(1<<3)|(1<<4)|(1<<5);
        int maskB=(1<<4)|(1<<5)|(1<<6)|(1<<7);
        int maskC=(1<<6)|(1<<7)|(1<<8)|(1<<9);

        int result=(n-mp.size()) *2;

        for(auto& [row ,rowMask]:mp)
        {
            bool CaseA=(maskA & rowMask)==0;
             bool CaseB=(maskB & rowMask)==0;
              bool CaseC=(maskC & rowMask)==0;

              if(CaseA && CaseC)
              {
                result+=2;
              }
             else if(CaseA || CaseB || CaseC)
              {
                result+=1;
              }
        }
        return result;
    }
};