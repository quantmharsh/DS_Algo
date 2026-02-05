// //Leetcode:213. House Robber II
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000
 


class Solution {
public:
//this means t[i] .   in i house  this is the max that we can steal;
vector<int> t;
//Approach 1 : Recursion+Memoization
//We will have two cases
//case 1:take first house then dont take last house so rage is(0 , n-1)
//case 2:dont take first house take last house so range is(1 , n);
//at last take the max of both

/*
    int solve(vector<int>& nums , int i , int n)
    {
        if(i>n)
        {
            return 0;
        }
        if(t[i]!=-1)
        {
            return t[i];
        }
        int steal = nums[i]+solve(nums , i+2 , n);
        int skip=solve(nums , i+1 , n);
        return t[i]= max(steal ,skip);
    }
    int rob(vector<int>& nums) {
        int n =nums.size();
                if(n == 1)
            return nums[0];
        
        if(n == 2)
        {
            return max(nums[0], nums[1]);
        }
            
            
            t.resize(n+1);
        fill(t.begin() ,t.end() , -1);

        //take the house AT 0th index
        int result1= solve( nums , 0 , n-2);
         fill(t.begin() ,t.end() , -1);
        int result2=solve(nums , 1 , n-1);
        return max(result1 , result2);

        
    }*/

        int rob(vector<int>& nums) {
        int n =nums.size();
                if(n == 1)
            return nums[0];
        
        if(n == 2)
        {
            return max(nums[0], nums[1]);
        }
            
            
            t.resize(n+1);
        fill(t.begin() ,t.end() , -1);

      //Case 1:When we take the 0th index house then dont take last index
      t[0]=0;
      for(int i=1;i<=n-1;i++)
      {
        int steal =nums[i-1]+(i-2>=0?t[i-2] :0);
        int skip= t[i-1];
        t[i]=max(steal ,skip);
        
      }
      int result1=t[n-1];
         fill(t.begin() ,t.end() , -1);
      //Case2:when we take the 1st house then take last house also
           t[0]=0;
           t[1]=0;
      for(int i=2;i<=n;i++)
      {
        int steal =nums[i-1]+(i-2>=0?t[i-2] :0);
        int skip= t[i-1];
         t[i]=max(steal ,skip);
        
      }
      int result2= t[n];
      return max(result1 ,result2);


        
    }
}; 