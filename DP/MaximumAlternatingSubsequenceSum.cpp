// //Leetcode:1911Maximum Alternating Subsequence Sum
// The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the sum of the elements at odd indices.

// For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
// Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the elements of the subsequence).

// A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.

 

// Example 1:

// Input: nums = [4,2,5,3]
// Output: 7
// Explanation: It is optimal to choose the subsequence [4,2,5] with alternating sum (4 + 5) - 2 = 7.
// Example 2:

// Input: nums = [5,6,7,8]
// Output: 8
// Explanation: It is optimal to choose the subsequence [8] with alternating sum 8.
// Example 3:

// Input: nums = [6,2,1,2,4,5]
// Output: 10
// Explanation: It is optimal to choose the subsequence [6,1,5] with alternating sum (6 + 5) - 1 = 10.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
class Solution {
public:
int n ;
//Approach 1: Using Recusion +Memoization
//we will have a flag  and update it on basis of  index
//if even index then flag is 0 or else 1 
    long long  t[1000001][2];
    long long solve(int index , vector<int>& nums , bool flag)
    {
        if(index>=n)
        {
            return 0;
        }
        if(t[index][flag]!=-1)
        {
            return t[index][flag];
        }
        
         long long skip=solve(index+1 ,nums ,flag);
         long long val=nums[index];
            //odd index  change val to -
         if(flag!=true)
         {
            val=-val;
         }
         long long take= val+solve(index+1 , nums , !flag);
        // t[index][flag]=max(skip ,take);
        // cout<<"index:"<<index<<"flag:"<<flag <<"="<<t[index][flag]<<endl;
       return t[index][flag]=max(skip ,take);
      
         

    }
    long long maxAlternatingSum(vector<int>& nums) {
         n=nums.size();
         // 0 index->even->flag=true;
         memset(t , -1 , sizeof(t));
         return solve(0 , nums  , true);       
    }



      //Approach 2: Bottom Up Approach
    //When we take the index  i then we have  2 scenarios
    //1. Array length becomes even :
    //when it becomes even then we find max of (subtract nums[i] from last odd(take case)  ,last even(skip case))
    //2.Array length becomes odd:
    //when it becomes odd  then then we find max of(add nums[i] from last even , last odd (Skip case))
    //At last return  max of t[n][0] and t[n][1];
    long long maxAlternatingSum(vector<int>& nums) {
       long long  n=nums.size();
        long long t[n+1][2];
        memset(t , 0 ,sizeof(t));
        for(long long i =1;i<=n;i++)
        {
            //even case
            t[i][0]= max(t[i-1][1]-nums[i-1] ,t[i-1][0]);
            //odd case
            t[i][1]=max(t[i-1][0]+nums[i-1] , t[i-1][1]);
        }

        return max(t[n][0] ,t[n][1]);
        
    }
};
