// //Leetcode:2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
// You are given a 0-indexed array of integers nums.

// A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of nums[0] is sequential.

// Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.

 

// Example 1:

// Input: nums = [1,2,3,2,5]
// Output: 6
// Explanation: The longest sequential prefix of nums is [1,2,3] with a sum of 6. 6 is not in the array, therefore 6 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.
// Example 2:

// Input: nums = [3,4,5,1,12,14,13]
// Output: 15
// Explanation: The longest sequential prefix of nums is [3,4,5] with a sum of 12. 12, 13, and 14 belong to the array while 15 does not. Therefore 15 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.
 

// Constraints:

// 1 <= nums.length <= 50
// 1 <= nums[i] <= 50

class Solution {
public:
    //Approach: Hash Table
    // i will have sum =nums[0] at starting then start loop ith i=1 to i<n and check if(nums[i]=nums[i-1]+1) if then add nums[i] in sum and continue loop . if we didnt get it then break of for loop . and now check whether sum exists in nums or not if not exists then return sum directly . otherwise if it exists then search for sum+1 is that also exists then continue until we not fpund sum , and return that sum
    int missingInteger(vector<int>& nums) {
        unordered_set <int> st(nums.begin() , nums.end());
        int sum =nums[0];
        for(int i =1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1]+1)
            {
                sum+=nums[i];
            }
            else{
                break;
            }
        }
     //  cout<<"sum"<<sum<<endl;

        //find sum which doesnt exists in nums
        while(st.count(sum)!=0)
        {
            sum++;
        }
        return sum;


        
    }
};