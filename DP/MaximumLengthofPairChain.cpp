// //Leetcode: 646.Maximum Length of Pair Chain
// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

// Return the length longest chain which can be formed.

// You do not need to use up all the given intervals. You can select pairs in any order.

 

// Example 1:

// Input: pairs = [[1,2],[2,3],[3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4].
// Example 2:

// Input: pairs = [[1,2],[7,8],[4,5]]
// Output: 3
// Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 

// Constraints:

// n == pairs.length
// 1 <= n <= 1000
// -1000 <= lefti < righti <= 1000\

class Solution {
public:
    //Approach 1:Using Recursion+Memoization
    //same approach as LIS(Leetcode:300)

    int n;
    int t[1001][1001];
    int solve(int prev , int index ,vector<vector<int>>& pairs)
    {
        if(index==n)
        {
            return 0;
        }
        if(prev!=-1 && t[index][prev]!=-1)
        {
            return t[index][prev];
        }
        int take=0;
        if(prev==-1 || pairs[prev][1]<pairs[index][0])
        {
        take=1+solve(index , index+1 , pairs);
        }
        int skip =solve(prev , index+1 ,pairs);
        if(prev!=-1 )
        {
            t[index][prev]=max(take ,skip);
        }
        return max(take ,skip);

        


    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        sort(pairs.begin() ,pairs.end());
        memset(t ,-1 ,sizeof(t));
        return solve(-1 , 0 , pairs);

        
    }
};