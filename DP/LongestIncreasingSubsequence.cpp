// //Leetcode: 300 Longest Increasing Subsequence
// Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104
 

// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

class Solution {
public:
int n;
int t[2501][2501];
//Note: Whenever Question is about subsequence always try to use Take and skip 
//Approach 1: Using recursion and memoization
//we will  take value at index i then our size increase by 1
//while taking check if  value at P(Previous index) is less then nums[i] then only pick
//if we skip then size will be same just move to next index
//To add memoization take 2D Vector since 2 variables are changing

    int solve(int index , int prev , vector<int>&nums)
    {
        if(index==n)
        {
            return 0;
        }
        //take ,skip
        //take
        int take=0;
       
        if(prev!=-1 && t[prev][index]!=-1)
        {
            
            return t[prev][index];
        }
        
        if(prev==-1 || nums[prev]<nums[index])
        {
            //prev index will be i now since we added ith element
             take =1+solve(index+1 , index , nums);
        
        }
        //if skiping then just move to next index .prev will not change 
        int  skip=solve(index+1 , prev ,nums );
         if(prev!=-1)
         {
           t[prev][index]=max(take ,skip);
         }
         return max(take ,skip);

    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(t , -1 ,sizeof(t));
        return solve(0 ,-1 , nums) ;


        
    }
};