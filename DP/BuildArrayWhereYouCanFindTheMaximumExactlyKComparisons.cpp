// //Leetcode: 1420 .Build Array Where You Can Find The Maximum Exactly K Comparisons
// You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:


// You should build the array arr which has the following properties:

// arr has exactly n integers.
// 1 <= arr[i] <= m where (0 <= i < n).
// After applying the mentioned algorithm to arr, the value search_cost is equal to k.
// Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.

 

// Example 1:

// Input: n = 2, m = 3, k = 1
// Output: 6
// Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
// Example 2:

// Input: n = 5, m = 2, k = 3
// Output: 0
// Explanation: There are no possible arrays that satisfy the mentioned conditions.
// Example 3:

// Input: n = 9, m = 1, k = 1
// Output: 1
// Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
 

// Constraints:

// 1 <= n <= 50
// 1 <= m <= 100
// 0 <= k <= n

class Solution {
public:
    int N ;
    int M ;
    int  K;
    int t[51][101][51];
    int mod=1e9+7;
    //Approach :Using Recursion+Memoization
    //T.C : O(m*n*k)
    //it is hard version of LIS approach
    //we need to create array and at each index we can store multiple values
    //so there is option .
    //for each index we will loop from i =1 to i<=m 
    //will return  number of ways to build array
    int solve(int index ,int maxValue , int searchCost )
    {
        if(index==N)
        {if(searchCost==K)
        {
            return 1;
        }
            return 0;
        }
        if( t[index][maxValue][searchCost] !=-1)
        {
            return  t[index][maxValue][searchCost] ;
        }
        int result=0;
        for(int i=1;i<=M;i++)
        {
            if(i>maxValue)
            {
            result=(result+solve(index+1  , i ,searchCost+1))%mod;
            }
            else{
                result=(result+solve(index+1 , maxValue ,searchCost))%mod;
            }
           
        }
        return t[index][maxValue][searchCost] = result%mod;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(t ,-1,sizeof(t));
        return solve(0 ,0 , 0);
        
    }
};  
