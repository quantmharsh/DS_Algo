// //Leetcode:3041. Maximize Consecutive Elements in an Array After Modification
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 0-indexed array nums consisting of positive integers.

// Initially, you can increase the value of any element in the array by at most 1.

// After that, you need to select one or more elements from the final array such that those elements are consecutive when sorted in increasing order. For example, the elements [3, 4, 5] are consecutive while [3, 4, 6] and [1, 1, 2, 3] are not.

// Return the maximum number of elements that you can select.

 

// Example 1:

// Input: nums = [2,1,5,1,1]
// Output: 3
// Explanation: We can increase the elements at indices 0 and 3. The resulting array is nums = [3,1,5,2,1].
// We select the elements [3,1,5,2,1] and we sort them to obtain [1,2,3], which are consecutive.
// It can be shown that we cannot select more than 3 consecutive elements.
// Example 2:

// Input: nums = [1,4,7,10]
// Output: 1
// Explanation: The maximum consecutive elements that we can select is 1.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 106

class Solution {
public:
    //Approach 1: Using Recursion +Memoization
    // Sort the array in ascending order.
// For each element, consider it as the starting element of a consecutive sequence.
// We have two options to find the next consecutive element:
// Option 1: Search for currVal + 1 in the remaining array. If found, use it without modification and recursively call solve(j, 0).
// Option 2: Search for currVal in the remaining array. If found, increase it by 1 to make it currVal + 1 and recursively call solve(j, 1).
// Use the inc parameter to track whether the current element has been increased by 1.
// Calculate the maximum sequence length by adding 1 (for the current element) to the recursive result of each valid option.
// Return the maximum length obtained from both options.
// Use memoization to avoid recalculating already computed states.
    int n;
    vector<vector<int>> memo;   
    int findNumber(int target , int i , vector<int>& nums)
    {
        int j = lower_bound(nums.begin()+i , nums.end() , target)-nums.begin();
 
        if(j<n && nums[j]==target)
        {
            return j;
        } 
        return -1;  
    }
    int solve(int index , int inc , vector<int>& nums)
    {
        if(memo[index][inc]!=-1)
        {
            return memo[index][inc];
        }
        int currVal=nums[index]+inc;
        int len =1;
        // Option 1: Search for currVal + 1 in the remaining array. If found, use it without modification and recursively call solve(j, 0).
        int j =findNumber(currVal +1 , index+1 , nums);
        if(j!=-1)
        {
            len=max(len , 1+solve(j , 0 , nums));
        }
        // Option 2: Search for currVal in the remaining array. If found, increase it by 1 to make it currVal + 1 and recursively call solve(j, 1).
        j=findNumber(currVal  , index+1 , nums);
        if(j!=-1)
        {
            len =max(len , 1+solve(j , 1 , nums));
        }

        return memo[index][inc]=len;

    }

    int maxSelectedElements(vector<int>& nums) {
        n=nums.size();
        memo.assign(n+1,vector<int>( 2 ,-1));
        sort(nums.begin() , nums.end());
        int result=1;
        for(int i =0;i<n;i++)
        {
            result=max ({result  ,solve(i , 0, nums) ,solve(i , 1, nums)});
        }
        return result;
        
    }
};