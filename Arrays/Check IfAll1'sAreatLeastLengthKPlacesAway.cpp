// //Leetcode: 1437 Check If All 1's Are at Least Length K Places Away.cpp
// Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.

 

// Example 1:


// Input: nums = [1,0,0,0,1,0,0,1], k = 2
// Output: true
// Explanation: Each of the 1s are at least 2 places away from each other.
// Example 2:


// Input: nums = [1,0,0,1,0,1], k = 2
// Output: false
// Explanation: The second 1 and third 1 are only one apart from each other.
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= k <= nums.length
// nums[i] is 0 or 1

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
     int cnt=0;
     int last1=-(k+1);
     int diff=0;
     int n =nums.size();
     for(int  i=0;i<n;i++)
     {
      if(i==0 && nums[i]==1)
      {
        last1=0;
      }
      else if(nums[i]==1)
      {
        diff=i-last1-1;
        if(diff<k)
        {
            return false;
        }
        last1=i;
      }

     } 
     return true;  
    }
};