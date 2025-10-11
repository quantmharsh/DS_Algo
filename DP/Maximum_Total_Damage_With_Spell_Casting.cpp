// //Leetcode:3186. Maximum Total Damage With Spell Casting
// A magician has various spells.

// You are given an array power, where each element represents the damage of a spell. Multiple spells can have the same damage value.

// It is a known fact that if a magician decides to cast a spell with a damage of power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.

// Each spell can be cast only once.

// Return the maximum possible total damage that a magician can cast.

 

// Example 1:

// Input: power = [1,1,3,4]

// Output: 6

// Explanation:

// The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with damage 1, 1, 4.

// Example 2:

// Input: power = [7,1,6,6]

// Output: 13

// Explanation:

// The maximum possible damage of 13 is produced by casting spells 1, 2, 3 with damage 1, 6, 6.

 

// Constraints:

// 1 <= power.length <= 105
// 1 <= power[i] <= 109




//Approach- Recursion + Memoization
//T.C : O(nlogn)
//S.C : O(n)


class Solution {
public:
    unordered_map<long long ,long long> mp;
    vector<long long>t;

    long long solve(vector<long long > & nums ,int i)
    {
        int n =nums.size();
        if(i>=n)
        {
            return 0;
        }
        if(t[i]!=-1)
        {
            return t[i];
        }

        long long skip =solve(nums, i+1);
        //taking up ith index power
        int j =lower_bound(nums.begin()+i+1 , nums.end(), nums[i]+3)-nums.begin();
        long long taken =nums[i]*mp[nums[i]]+solve(nums , j);
        return t[i]= max(skip ,taken);

    }

    long long maximumTotalDamage(vector<int>& power) {

       
      
        
        for(auto it:power)
        {
            mp[it]++;
        }
          vector<long long>nums(mp.size());
         //store only unique element
    for(auto &it: mp)
   {
    nums.push_back(it.first);
    }
     int n =nums.size();
  sort(begin(nums), end(nums));
  t.assign(n ,-1);

    return solve(nums , 0);}

};