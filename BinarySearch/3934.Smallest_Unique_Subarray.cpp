// //leetcode:3934. Smallest Unique Subarray
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums.

// Find the minimum length of a subarray that is not identical to any other subarray in nums.

// Return an integer denoting the minimum possible length of such a subarray.

// Two subarrays are considered identical if they have the same length and the same elements in corresponding positions.

 

// Example 1:

// Input: nums = [3,3,3]

// Output: 3

// Explanation:

// Subarrays of length 1: [3] → appears 3 times
// Subarrays of length 2: [3, 3] → appears 2 times
// Subarrays of length 3: [3, 3, 3] → appears once
// The subarray [3, 3, 3] is unique, so the smallest unique subarray length is 3.

// Example 2:

// Input: nums = [2,1,2,3,3]

// Output: 1

// Explanation:

// Subarrays of length 1:

// [2] → appears 2 times
// [1] → appears once
// [3] → appears 2 times
// The subarray [1] is unique, so the smallest unique subarray length is 1.
// Example 3:

// Input: nums = [1,1,2,2,1]

// Output: 2

// Explanation:

// Subarrays of length 1:

// [1] → appears 3 times
// [2] → appears 2 times
// Subarrays of length 2:

// [1, 1] → appears once
// [1, 2] → appears once
// [2, 2] → appears once
// [2, 1] → appears once
// There is at least one subarray of length 2 that is unique, so the smallest unique subarray length is 2.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
class Solution {
public:
    //Approach: Binary Search+ Sliding Window + Rolling Hash
    //instead of bruteforcing for every size. we will apply binary search to find smallest unique subarray
    //start from mid and if we find ans then reduce size more 
    //we cant store  subarray of size  n each element in vector map . it has higher time complexity . for ex <{1,1,2} ,1>  
    //Instead we will store its hash . by this we can easily find if anyother subarray exist which ahve smae hash .we will increase its count in map
    //at last if we have any hash which have cnt=1 we will return true . and that size will be our ans
    //--------Calculate Hash-----------------
    //we will find max element in array and its +1 will be base . for ex max=2 , base=2+1=3
    //hash=hash*base+nums[j]
    //we will do this until size current size is less then our  subarray size which we are considering(mid)
    //if w its equal to mid . then in mp[hash] we will increase its count
    //and remove hash of first value . from our hash to get hash of remaining no. by this we will
    //have to not calcualte hash again for particular window 
    //for ex : hash of  [1,1,2]=14 . remove hash of 1 nums[0]. whose hash will be calcualted total of  nums[0]*base^size-1   . 1*3^2=9
    //remove it from hash. hash = nums[i]*base^size-1
    ///-----------------done------------------------
    //Afer coming outof while loop. check if we have any hash in map which  have cnt =1
    //if we have then return true else false
    //Do same for every iteration .

   
    int n;
    int MOD = 1e9+7;
    // Binary exponentiation
    long long  findPower(long long a, long long  base) {
        if (base == 0) {
            return 1;
        }

        long long half = findPower(a, base / 2);
        long long result = (half * half) % MOD;
        if (base % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }
    bool isUniqueSubArray(vector<int>& nums , int size , int base)
    {
        unordered_map<long long , int > mp;
        int i =0;
        int j =0;
        long long P=findPower(base,size-1);
        long long hash =0;
        while(j<n)
        {
            hash =(hash*base+nums[j])%MOD;
            if(j-i+1<size)
            {
                j++;
            }
            else{
                mp[hash]++;
                //removenums[i] hash from our ovverlal hash
                hash=(hash-(nums[i]*P)%MOD+MOD)%MOD ;
                i++;
                j++;
            }
        }

        for(auto &it: mp)
        {
            if(it.second==1)
            {
                return true;
            }
        }
        return false;
        
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        n=nums.size();
        int l =1;
        int r=n;
        int base= *max_element(nums.begin() , nums.end()) +1;
        int mid=0;
        int result=n;
        while(l<=r)
        {
         mid= l+(r-l)/2;
         if(isUniqueSubArray(nums  , mid  , base))
         {
            result=mid;
            r=mid-1;
         }else{
            l=mid+1;
         }


        }
        return result;
               
    }
};