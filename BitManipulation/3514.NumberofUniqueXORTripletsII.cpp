// //Leetcode:3514. Number of Unique XOR Triplets II
// You are given an integer array nums.

// A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.

// Return the number of unique XOR triplet values from all possible triplets (i, j, k).

 

// Example 1:

// Input: nums = [1,3]

// Output: 2

// Explanation:

// The possible XOR triplet values are:

// (0, 0, 0) → 1 XOR 1 XOR 1 = 1
// (0, 0, 1) → 1 XOR 1 XOR 3 = 3
// (0, 1, 1) → 1 XOR 3 XOR 3 = 1
// (1, 1, 1) → 3 XOR 3 XOR 3 = 3
// The unique XOR values are {1, 3}. Thus, the output is 2.

// Example 2:

// Input: nums = [6,7,8,9]

// Output: 4

// Explanation:

// The possible XOR triplet values are {6, 7, 8, 9}. Thus, the output is 4.

 

// Constraints:

// 1 <= nums.length <= 1500
// 1 <= nums[i] <= 1500

class Solution {
public:
//Approach: Create a  i ,j indexes  oxor and store itunique value
//then xor  eaxch pair with j index sand store in set s2 and return s2 size 
    int uniqueXorTriplets(vector<int>& nums) {
            int  n= nums.size();
            unordered_set<int> s1;
            unordered_set<int>s2;
            for(int i =0;i<n;i++)
            {
                for(int j =i;j<n;j++)
                {
                    s1.insert(nums[i]^nums[j]);
                }
            }
            
            //create a triplet 
            for(auto it:s1)
            {
                for(int i=0;i<n;i++ )
                {
                    s2.insert(it^nums[i]);
                }
            }
            return s2.size();
    
    }
};