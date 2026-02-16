// //Leetcode :368.Largest Divisible Subset
// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.
// Example 2:

// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 2 * 109
// All the integers in nums are unique.

class Solution {
public:
    //Approach 1: Using recursion+Memoization
    //This is similar to LIS. But here we can rearrange since we require subset.so we will sort it
    //But this Approach gives us TLE since we will be using temp vector which will also change
    // int n;
    // vector<int>result;
    // vector<int>temp;
    // int t[1001][1001];
    // void solve(int prev , int index ,  vector<int> &temp , vector<int> &result ,vector<int>& nums)
    // {   
    //     //Base case
    //     if(index>=n)
    //     {
    //         if(temp.size()>result.size())
    //         {
    //             result=temp;
    //         }
    //         return;
    //     }
    //     if(prev==-1 || nums[index]%prev==0)
    //     {
    //     temp.push_back(nums[index]);
    //     solve(nums[index] , index+1 ,temp ,result , nums);
    //     temp.pop_back();
            
    //     }
    //     solve(prev,index+1 ,temp ,result , nums);

        
    // }
    // vector<int> largestDivisibleSubset(vector<int>& nums) {
    //     n=nums.size();
    //     sort(nums.begin() , nums.end());
    //     solve(-1 , 0 , temp , result , nums);
    //     return result;


    

    // }
    //Approach 2: Bottom UP LIS Approach With few changes 
    //Here we will have previndex vector which will store the index of prev value whch is part of this subset
    //we will have a variable last_index  which will help us to know which index have largest value
    //and a vector t which will store longest subset till ith index
//whenever maxL get updated we will also update our lastindex 


        vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin() , nums.end());
        vector<int> t(n ,1);
        vector<int> prevIndex(n , -1);
        vector<int>result;
        int lastIndex=0;
        int maxL=1;

        for(int i=1;i<n;i++)
        {
        for(int j =0;j<i;j++)
        {
            if(nums[i]%nums[j]==0)
            {
                if(t[i]<t[j]+1)
                {
                 t[i]= t[j]+1;
                prevIndex[i]=j;
                }
                if(t[i]>maxL)
                {
                    maxL=t[i];
                    lastIndex=i;
                }
                
            }
        }
        }
        while(lastIndex>=0)
        {
            result.push_back(nums[lastIndex]);
            lastIndex=prevIndex[lastIndex];
        }


        return result;


    

    }
};