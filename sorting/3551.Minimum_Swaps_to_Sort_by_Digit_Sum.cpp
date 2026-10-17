// //Leetcode:3551. Minimum Swaps to Sort by Digit Sum
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array nums of distinct positive integers. You need to sort the array in increasing order based on the sum of the digits of each number. If two numbers have the same digit sum, the smaller number appears first in the sorted order.

// Return the minimum number of swaps required to rearrange nums into this sorted order.

// A swap is defined as exchanging the values at two distinct positions in the array.

 

// Example 1:

// Input: nums = [37,100]

// Output: 1

// Explanation:

// Compute the digit sum for each integer: [3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]
// Sort the integers based on digit sum: [100, 37]. Swap 37 with 100 to obtain the sorted order.
// Thus, the minimum number of swaps required to rearrange nums is 1.
// Example 2:

// Input: nums = [22,14,33,7]

// Output: 0

// Explanation:

// Compute the digit sum for each integer: [2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] → [4, 5, 6, 7]
// Sort the integers based on digit sum: [22, 14, 33, 7]. The array is already sorted.
// Thus, the minimum number of swaps required to rearrange nums is 0.
// Example 3:

// Input: nums = [18,43,34,16]

// Output: 2

// Explanation:

// Compute the digit sum for each integer: [1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] → [9, 7, 7, 7]
// Sort the integers based on digit sum: [16, 34, 43, 18]. Swap 18 with 16, and swap 43 with 34 to obtain the sorted order.
// Thus, the minimum number of swaps required to rearrange nums is 2.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// nums consists of distinct positive integers.

class Solution {
public: 
//Approach: Hashmap
// Create a copy of the original array and sort it by digit sum in ascending order.
// If two numbers have the same digit sum, sort them by their values in ascending order.

// Store each number's original index in a hashmap.

// Create a visited array to track the indices that have already been processed.
  
// Traverse the sorted array and skip indices that are already visited or are already in the correct position.

// Follow the original index mappings to identify a cycle.

// Count the number  of indices in each cycle and add `cycleLength - 1` to the total swap count.

// Return the total minimum number of swaps.
    
    int calculateDigitSum(int num)
    {
        int sum=0;
        while(num>0)
        {
            sum+=num%10;
            num=num/10;
        } 
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        
        int n =nums.size();
        vector<int> sortedNums(nums);
        vector<bool> visited (n  ,false);
        unordered_map<int , int> originalIndex;
        int swaps=0;
    //    cout<<"Reached Here 1"<<endl;
        auto lambda= [&](int num1 , int num2){ 
            int num1DigitSum=calculateDigitSum(num1);
            int num2DigitSum=calculateDigitSum(num2);
             if(num1DigitSum==num2DigitSum)
             {
                return num1<num2;

             }
             return num1DigitSum <num2DigitSum;

        };
        sort(sortedNums.begin()  , sortedNums.end() , lambda);
    //    cout<<"Reached here 2"<<endl; 
        for(int i =0;i<n;i++)
        {
            originalIndex[nums[i]]=i;
        }
   //     cout<<"reached here 3"<<endl;
        for(int i=0;i<n;i++)
        {   
            if(visited[i] || originalIndex[sortedNums[i]]==i)
                {
                    continue;
                }
            int curr_i =i;
            int cycleLength=0;
            while(!visited[curr_i])
            {
                
                visited[curr_i]=true;
                curr_i=originalIndex[sortedNums[curr_i]];
                cycleLength++;
            }
            swaps+=(cycleLength-1);
          //  cout<<"Updated swaps"<<endl;
        }  
        return swaps; 
         
        

    }
};