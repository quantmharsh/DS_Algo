// //leetcode:3702. Longest Subsequence With Non-Zero Bitwise XOR
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums.

// Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.
 
 

// Example 1:

// Input: nums = [1,2,3]

// Output: 2

// Explanation:

// One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.

// Example 2:

// Input: nums = [2,3,4]

// Output: 3

// Explanation:

// The longest subsequence is [2, 3, 4]. The bitwise XOR is computed as 2 XOR 3 XOR 4 = 5, which is non-zero.

 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109
class Solution {
public:
    //Approach: Bit Manipulation
    //here we need to find longest subsequece with non zero bitwise xor means 
    //when we xor 2 numbers then its xor should not be 0.
    //so here is a trick we will find xor of all numbers
    //if xor of all numbers in 0 then ans is n-1 . else n 
    //for ex 1^2^3 => 3^3=0 . so we can take 1^2=3 which is not zero
    //corner case . if all nums is 0 then ans will be 0 
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        bool allZeros=true;
        int  xorOfNum=0;
        for(int i =0;i<n;i++)
        {
            xorOfNum =xorOfNum^nums[i];
            if(nums[i]!=0)
            {
                allZeros=false;
            }

        }
        if(allZeros)
        {
            return 0;
        }
        return xorOfNum==0?n-1:n;
    }
};