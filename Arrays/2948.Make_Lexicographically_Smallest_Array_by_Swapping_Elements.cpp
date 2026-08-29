// //Leetcode:2948. Make Lexicographically Smallest Array by Swapping Elements
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 0-indexed array of positive integers nums and a positive integer limit.

// In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.

// Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

// An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.

 

// Example 1:

// Input: nums = [1,5,3,9,8], limit = 2
// Output: [1,3,5,8,9]
// Explanation: Apply the operation 2 times:
// - Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
// - Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
// We cannot obtain a lexicographically smaller array by applying any more operations.
// Note that it may be possible to get the same result by doing different operations.
// Example 2:

// Input: nums = [1,7,6,18,2,1], limit = 3
// Output: [1,6,7,18,1,2]
// Explanation: Apply the operation 3 times:
// - Swap nums[1] with nums[2]. The array becomes [1,6,7,18,2,1]
// - Swap nums[0] with nums[4]. The array becomes [2,6,7,18,1,1]
// - Swap nums[0] with nums[5]. The array becomes [1,6,7,18,1,2]
// We cannot obtain a lexicographically smaller array by applying any more operations.
// Example 3:

// Input: nums = [1,7,28,19,10], limit = 3
// Output: [1,7,28,19,10]
// Explanation: [1,7,28,19,10] is the lexicographically smallest array we can obtain because we cannot apply the operation on any two indices.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 1 <= limit <= 109
 
class Solution {
public:

    //Appraoch: Array  . Hashmap , List
    //sort the  nums and create different groups for ex(0 , 1, 2)
    //after sorting if nums[i]-nums[i-1] <limit then they are in same group
    //else increase groupnumber count and store that nums[i] in new group
    //also map num[i] to group for ex 10-1 10 is in group 1 -> in map go to group1 key and pick
    //smallest value from it since it is already sorted 
    //traverse nums . check nums[i] in which group it is . go to that group no and pick smallest
    //value from that group and store in res[i] . also pop out smallest no. 
    //Fot popping out  if we use vector it TC O(n) so we  are  using list which  have TC(1)
    //which uses pointer similar to like linked list
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n =nums.size();
        vector<int> vec= nums;
        unordered_map<int , int > numToGroup;
        unordered_map<int , list<int>> groupToList;
        int groupNumber=0;
        //sort vec
        sort(vec.begin() , vec.end());

        numToGroup[vec[0]]=groupNumber;
        groupToList[groupNumber].push_back(vec[0]);
        
        //create groups
        for(int i =1;i<n;i++)
        {
            //update groupnumber
            if(abs(vec[i-1]-vec[i]) >limit)
            {
                groupNumber++;
            }
            numToGroup[vec[i]]=groupNumber;
            groupToList[groupNumber].push_back(vec[i]);
        }
        
        //now  build result
        vector<int>result(n);
        for(int i=0;i<n;i++)
        {
            int  group= numToGroup[nums[i]];
            result[i]=*(groupToList[group].begin());
            groupToList[group].pop_front();

        }
        return result;

    }
};