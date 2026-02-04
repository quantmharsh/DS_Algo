// //Leetcode: 198 House Robber
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400
 

class Solution {
public:
vector<int> t;
//Approach 1 : Recusrion +Memoization
//we have 2 scenario either steal ith house or skip the ith house 
//We will store max of both scenario
/*
    
    int solve(vector<int>& nums , int i , int n)
    {
        if(i>=n)
        {
            return 0;
        }
        if(t[i] != -1)
        {
            return t[i];
        }
        int steal =nums[i]+solve(nums ,i+2 , n);
        int skip=solve(nums , i+1 , n);
        return t[i]=max(steal ,skip);
    }



    int rob(vector<int>& nums) {
        int n =nums.size();
        t.resize(n);
        fill(t.begin() ,t.end() , -1);
        return solve(nums , 0 , n);
        
    }
*/



//Approach 2 Bottom up approach 

     int rob(vector<int>& nums) {
        int n =nums.size();
        
        t.resize(n+1);
        fill(t.begin() ,t.end() , -1);
        t[0]=0;
        t[1]=nums[0];
        for(int i =2;i<=n;i++)
        {
            int steal=nums[i-1]+t[i-2];
            int skip=t[i-1];

            t[i]=max(steal ,skip);
        }
        return t[n];
        
    }
};