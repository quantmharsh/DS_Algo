// //Leetcode:3483. Unique 3-Digit Even Numbers

// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.

// Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.

 

// Example 1:

// Input: digits = [1,2,3,4]

// Output: 12

// Explanation: The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed because there is only 1 copy of the digit 2.

// Example 2:

// Input: digits = [0,2,2]

// Output: 2

// Explanation: The only 3-digit even numbers that can be formed are 202 and 220. Note that the digit 2 can be used twice because it appears twice in the array.

// Example 3:

// Input: digits = [6,6,6]

// Output: 1

// Explanation: Only 666 can be formed.

// Example 4:

// Input: digits = [1,3,5]

// Output: 0

// Explanation: No even 3-digit numbers can be formed.

 

// Constraints:

// 3 <= digits.length <= 10
// 0 <= digits[i] <= 9

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
       vector<int> mp(10 ,0);
       vector<int>result;
       int cnt=0;
       for(int i =0;i<digits.size();i++)
       {
        mp[digits[i]]++;
       }
       for(int i=1;i<=9;i++)
       {
        if(mp[i]==0) continue;
        mp[i]--;
        for(int j =0;j<=9;j++)
        {
            if(mp[j]==0) continue;
        mp[j]--;

            for(int k =0;k<=8;k=k+2)
            {
                if(mp[k]==0) continue;
              mp[k]--;
             cnt++;
              mp[k]++;

            }
            mp[j]++;
        }
        mp[i]++;
       }
       return cnt;

    }
};