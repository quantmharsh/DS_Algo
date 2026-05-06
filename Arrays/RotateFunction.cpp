// //Leetcode:396. Rotate Function
// Medium
// Topics
// premium lock icon
// Companies
// You are given an integer array nums of length n.

// Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

// F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
// Return the maximum value of F(0), F(1), ..., F(n-1).

// The test cases are generated so that the answer fits in a 32-bit integer.

 

// Example 1:

// Input: nums = [4,3,2,6]
// Output: 26
// Explanation:
// F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
// F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
// F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
// F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
// So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
// Example 2:

// Input: nums = [100]
// Output: 0
 

// Constraints:

// n == nums.length
// 1 <= n <= 105
// -100 <= nums[i] <= 100


class Solution {
public:
    //Approach:This Question cant be solved using DP since we dont have pick not pick options
    //Its a Maths observed problem
    //T.C : O(n)
    //S.C : O(1)
    //F(0)= 0.a0+1.a1+2.a2+...+n-2.an-2+n-1.an-1 
    //F(1)=1.a0+2.a1+3.a2+...+n-1an-2+0.an-1 
    //if we create equation from above 2 by subtractinf
    //F(0)-F(1)=a0+a1+a2+...+an-2-(n-1).an-1
    //F(0)-F(1)=a0+a1+a2+....+an-2-n.an-1+an-1
    //Rearrange equation
    //F(0)-F(1)=a0+a1+a2+....+an-2+an-1-n.an-1
    //F(0)-F(1)=SUM-n.an-1
    //F(1)=F(0)+SUM-n.an-1
    //Now problem that we have is how to identify  an-1
    //so here is the go through  for different values of k what is an-1
    //original array [4,3,2,6]
    // K array      Lastvalue   ItsIndexInOriginalArray  an-1
    // 0 [4,3,2,6]     6                  3              a[n-1-0]
    // 1 [6,4,3,2]     2                  2              a[n-1-1]    
    // 2 [2,6,4,3]     3                  1              a[n-1-2]
    // 3 [3,2,6,4]    4                    0             a[n-1-3]
    //forf(k)  an-1 will be a[n-1-k]
    //Therefore our final equation is 
    //F(K)=F(K-1)+SUM-n.a[n-1-k]  
    //Approah: we will calculate sum of all elements
    //and intially we will also be calculating f(0)
    //then we will start for loop from k=0 to k<n
    //each time we will calculate f(k) and update max value in ans 
    //and then update our f variable with fk so that we have f(k-1) value everytime when finding for f(k)


 int maxRotateFunction(vector<int>& nums) {


    int sum =0;
    int f=0;
    int n = nums.size();
    for(int i =0;i<n;i++)
    {
        sum=sum+nums[i];
        f=f+i*nums[i];
    }
    // We already have F(0) stored in 'f'.
// Now we iteratively compute F(1), F(2), ..., F(n-1) using the relation:
// F(k) = F(k-1) + totalSum - n * nums[n - k]
//
// In each iteration:
// - 'fk' represents the next rotation value F(k)
// - Update the maximum answer 'ans'
// - Update 'f' to fk so it becomes F(k-1) for the next step
//
// Note: When k = 0, this computes F(1) from F(0)
    int ans=f;  
    for(int k=0;k<n-1;k++)
    { 
        int fk=f+sum-n*nums[n-1-k];
        ans= max(ans ,fk);
        f=fk;
    }
    return ans;

    }
}; 
