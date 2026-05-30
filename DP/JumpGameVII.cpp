// //Leetcode: 1871. Jump Game VII
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

// i + minJump <= j <= min(i + maxJump, s.length - 1), and
// s[j] == '0'.
// Return true if you can reach index s.length - 1 in s, or false otherwise.

 

// Example 1:

// Input: s = "011010", minJump = 2, maxJump = 3
// Output: true
// Explanation:
// In the first step, move from index 0 to index 3. 
// In the second step, move from index 3 to index 5.
// Example 2:

// Input: s = "01101110", minJump = 2, maxJump = 3
// Output: false
 

// Constraints:

// 2 <= s.length <= 105
// s[i] is either '0' or '1'.
// s[0] == '0'
// 1 <= minJump <= maxJump < s.length

// class Solution {
// public:
//     //Approach 1: Recusrion+Memoization
//     //since only index is changing it is a single dp  question 
//     // we will start from index 0 and for each index we will check whether can we reach last index or not  by looping from minjump to maxjump
//     //if for any jump for particular index we are able to reach last index then in dp mark that index as true  so that whenever in future we reach this index then we dont need to check further because we are sure that from this index we can reach last index

//     bool solve(int index , int minJump , int maxJump , string& s, int n , vector<int>& t)
//     {
//         //base condition
//         if(index==n-1)
//         {
//             return true;
//         }
//         if(t[index]!=-1)
//         {
//             return  t[index];
//         }

//         for(int i =minJump ;i<=maxJump;i++)
//         {
//             int new_index= index+i;
//             if(new_index>=n)
//             {
//                 break;
//             }if(s[new_index]!='0')
//             {
//                 continue;
//                 }

//             if(solve(new_index , minJump , maxJump , s , n , t))
//             {
//                  return t[index]=true;
//             }

//         }
//         return t[index]=false;
//     }
//     bool canReach(string s, int minJump, int maxJump) {
//         int n= s.length();
//         vector<int>t(n ,-1);
//     return solve(0 , minJump , maxJump , s ,n,t) ;
        
//     }
// };


//NOTE:Copied solution from discuss section because of TLE in above approach
//Approach-3 (Sliding Window + Bottom Up)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();

        vector<int> t(n, 0);
        //t[i] > 0 : possible to reach i
        // == 0 : not possible to reach i

        t[0] = 1;
        int count = 0;

        for(int j = 1; j <= n-1; j++) {
            if(j - minJump >= 0) {
                count += t[j - minJump];
            }

            if(j - maxJump - 1 >= 0) {
                count -= t[j - maxJump - 1];
            }

            if(count > 0 && s[j] == '0') {
                t[j] = 1;
            }
        }

        return t[n-1] > 0;
    }
};
