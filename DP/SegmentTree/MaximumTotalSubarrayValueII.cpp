// //Leetcode:3691. Maximum Total Subarray Value II
// You are given an integer array nums of length n and an integer k.

// You must select exactly k distinct subarrays nums[l..r] of nums. Subarrays may overlap, but the exact same subarray (same l and r) cannot be chosen more than once.

// The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).

// The total value is the sum of the values of all chosen subarrays.

// Return the maximum possible total value you can achieve.

 

// Example 1:

// Input: nums = [1,3,2], k = 2

// Output: 4

// Explanation:

// One optimal approach is:

// Choose nums[0..1] = [1, 3]. The maximum is 3 and the minimum is 1, giving a value of 3 - 1 = 2.
// Choose nums[0..2] = [1, 3, 2]. The maximum is still 3 and the minimum is still 1, so the value is also 3 - 1 = 2.
// Adding these gives 2 + 2 = 4.

// Example 2:

// Input: nums = [4,2,5,1], k = 3

// Output: 12

// Explanation:

// One optimal approach is:

// Choose nums[0..3] = [4, 2, 5, 1]. The maximum is 5 and the minimum is 1, giving a value of 5 - 1 = 4.
// Choose nums[1..3] = [2, 5, 1]. The maximum is 5 and the minimum is 1, so the value is also 4.
// Choose nums[2..3] = [5, 1]. The maximum is 5 and the minimum is 1, so the value is again 4.
// Adding these gives 4 + 4 + 4 = 12.

 

// Constraints:

// 1 <= n == nums.length <= 5 * 10​​​​​​​4
// 0 <= nums[i] <= 109
// 1 <= k <= min(105, n * (n + 1) / 2)




class SegmentTree{
    public:
    vector<int> segmentTree;
    bool isMinTree;
    
    SegmentTree(vector<int>&nums , bool flag)
    {
        int n =nums.size();
        this->isMinTree=flag;
        segmentTree.resize(n*4);
        buildSegmentTree(0 ,0 , n-1 ,nums);
    }

    void buildSegmentTree(int i , int l , int r  ,vector<int>& nums)
    {
        if(l==r)
        {
            segmentTree[i]=nums[l];
            return;  
        }
        int mid=l+(r-l)/2;
        buildSegmentTree(2*i+1 , l , mid , nums);
        buildSegmentTree(2*i+2 ,mid+1  ,r, nums);
        if(isMinTree)
        {
            segmentTree[i]=min(segmentTree[2*i+2] ,segmentTree[2*i+1]);
        }
        else{
            segmentTree[i]=max(segmentTree[2*i+2] , segmentTree[2*i+1]);
        }
    }

    int querySegmentTree(int start , int end , int l , int r , int i)
    {
        if(l>end || r<start)
        {
            return isMinTree ? INT_MAX : INT_MIN;
        }

        // Complete overlap
        if(l>=start && r<=end)
        {
            return segmentTree[i];
        }
        int mid=l+(r-l)/2;
        int a= querySegmentTree(start  ,end ,l , mid,2*i+1);
        int b =querySegmentTree(start  ,end , mid+1 , r , 2*i+2);

        if(isMinTree)
        {
            return min(a ,b);
        }
       
            return max(b,a);
        
    }
    int query(int l , int r  , int n)
    {
        return querySegmentTree( l ,r , 0 , n-1 , 0);
    }



};
class Solution {
public:
//Approach: using Segment Tree And Max Heap
//At this point of time i am not aware of how segement tree and how calculate min and max value in a range 
//just using snippet of RMQ Segment Tree
//Step1: initialize Pq with best values starting l from 0 to n-1 and r fixed at n-1
//Step2:Find Top k element. when poping element from pq insert another element which have same  l  as popped element and reduce r ro r-1 and calculte min amx for (l ,r-1)
typedef long long ll;
ll getValue(int l, int r, SegmentTree& minST, SegmentTree& maxST, int n) {
        int minEl = minST.query(l, r, n);
        int maxEl = maxST.query(l, r, n);

        return (ll)maxEl - minEl;
    }
    
    
    long long maxTotalValue(vector<int>& nums, int k) {
         SegmentTree minSegmentTree(nums ,true);
         SegmentTree maxSegmentTree(nums , false);
        int n = nums.size();
        priority_queue<tuple<ll , int , int>> pq;
        ll result=0;


        //Step1: initialize Pq with best values starting l from 0 to n-1 and r fixed at n-1
        for(int l =0;l<n;l++)
        {
            ll value=getValue(l , n-1 ,minSegmentTree,maxSegmentTree ,n);
            pq.push({value , l , n-1}); 
        }

        //Step2:Find Top k element. when poping element from pq insert another element which have same  l  as popped element and reduce r ro r-1 and calculte min amx for (l ,r-1)

        while(k--)
        {
            auto[value , l ,r]=pq.top();
            result+=value;
            pq.pop();
            //push another element which have samw starting point
            ll nextElement= getValue(l , r-1 , minSegmentTree , maxSegmentTree  ,n);
            pq.push({nextElement , l , r-1});
        }
        return result;
    }
};