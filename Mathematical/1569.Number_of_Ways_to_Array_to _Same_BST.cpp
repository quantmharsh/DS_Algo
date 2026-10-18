// //leetcode:1569. Number of Ways to Reorder Array to Get Same BST
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

// For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.
// Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

// Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:


// Input: nums = [2,1,3]
// Output: 1
// Explanation: We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.
// Example 2:


// Input: nums = [3,4,5,1,2]
// Output: 5
// Explanation: The following 5 arrays will yield the same BST: 
// [3,1,2,4,5]
// [3,1,4,2,5]
// [3,1,4,5,2]
// [3,4,1,2,5]
// [3,4,1,5,2]
// Example 3:


// Input: nums = [1,2,3]
// Output: 0
// Explanation: There are no other orderings of nums that will yield the same BST.
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= nums.length
// All integers in nums are distinct.
class Solution {
public:
    //Approach: Maths 
    //we need to maintain original left right sequence.means root should be always
    //index at 0.
    //we have 1,2 at left of it. in new array we can keep it anywhere 
    //but there realative positions hould be same means 1 should be before 2 always
    //Same for right
    //We will store left and right in two different arrays
    //and then find  combinations to sotre left or right arrays in empty space (let z)
    // final ans is    leftsideCombination * rightsideCombination * z
    //To efficiently find combination of n-1Cr we will use pascal triangle
    //Build pascal triangle and pick PT[n-1][r]

   
      typedef long long ll;
       vector<vector<ll>> PT;
    ll MOD = 1e9 + 7;
    int solve(vector<int>& nums)
    {
        int n =nums.size();
        if(n<3)
        {
            return 1;
        }
        vector<int> leftArray;
        vector<int>rightArray;
        int root= nums[0];
        for(int i =1;i<n;i++)
        {
            if(nums[i]<root)
            {
                leftArray.push_back(nums[i]);
            }
            else{
                rightArray.push_back(nums[i]);
            }

        }
        ll x= solve(leftArray);
        ll y =solve(rightArray);
        ll r= leftArray.size();
        ll z= PT[n-1][r];
        return (((x*y)%MOD)*z)%MOD;

    }
    int numOfWays(vector<int>& nums) {
        int n =nums.size();
        PT.resize(n+1);
        for(int i =0;i<=n;i++)
        {
            PT[i]=vector<long long >(i+1 ,1);
            for(int  j =1;j<i ;j++)
            {
              PT[i][j] = (PT[i-1][j-1] + PT[i-1][j]) % MOD;
            }


        }

        return (solve(nums)-1)%MOD;
    }
};