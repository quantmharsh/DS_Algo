// //Leeetcode:3629. Minimum Jumps to Reach End via Prime Teleportation
// You are given an integer array nums of length n.

// You start at index 0, and your goal is to reach index n - 1.

// From any index i, you may perform one of the following operations:

// Adjacent Step: Jump to index i + 1 or i - 1, if the index is within bounds.
// Prime Teleportation: If nums[i] is a prime number p, you may instantly jump to any index j != i such that nums[j] % p == 0.
// Return the minimum number of jumps required to reach index n - 1.

 

// Example 1:

// Input: nums = [1,2,4,6]

// Output: 2

// Explanation:

// One optimal sequence of jumps is:

// Start at index i = 0. Take an adjacent step to index 1.
// At index i = 1, nums[1] = 2 is a prime number. Therefore, we teleport to index i = 3 as nums[3] = 6 is divisible by 2.
// Thus, the answer is 2.

// Example 2:

// Input: nums = [2,3,4,7,9]

// Output: 2

// Explanation:

// One optimal sequence of jumps is:

// Start at index i = 0. Take an adjacent step to index i = 1.
// At index i = 1, nums[1] = 3 is a prime number. Therefore, we teleport to index i = 4 since nums[4] = 9 is divisible by 3.
// Thus, the answer is 2.

// Example 3:

// Input: nums = [4,6,5,8]

// Output: 3

// Explanation:

// Since no teleportation is possible, we move through 0 → 1 → 2 → 3. Thus, the answer is 3.
 

// Constraints:

// 1 <= n == nums.length <= 105
// 1 <= nums[i] <= 106

class Solution {
public:

   //Approach (Using BFS + Sieve)
//
//Observation:
// We can treat each index as a node in a graph.
//
// From any index i, we can move:
// 1. To adjacent indices -> i-1 and i+1
// 2. Using teleportation:
//      If nums[i] is a prime number p,
//      then we can jump to every index j where nums[j] is divisible by p.
//
// Since every move/teleport costs exactly 1 jump,
// this becomes a shortest path problem in an unweighted graph.
//
// BFS is used because:
// - BFS explores all nodes level by level
// - The first time we reach an index,
//   it is guaranteed to be with minimum jumps
//
// Optimization:
// To efficiently check whether nums[i] is prime,
// we precompute all prime numbers using Sieve of Eratosthenes.
//
// We also use a hashmap:
//      value -> list of indices having that value
//
// This helps us quickly find all indices containing multiples
// of a prime number during teleportation.
//
// Additionally, we use a 'seen' set so that each prime number's
// teleportation is processed only once, avoiding repeated work.

    void solveSieve(vector<bool> &isPrime , int &maxElement)
    {
        isPrime.resize(maxElement+1 ,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i =2;i*i<=maxElement;i++)
        {
            if(isPrime[i])
            {
                for(int multiples=i*i;multiples<=maxElement;multiples+=i)
                {
                    isPrime[multiples]=false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        
        int n =nums.size();
        vector<bool>isPrime;
       unordered_map<int, vector<int>> mp;
        int maxElement=-1;
        //store all occurence of each  num appearing in array.nd also update maxelement
        for(int i =0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
            maxElement=max(maxElement , nums[i]);
        }

        solveSieve(isPrime ,maxElement);

        vector<bool>visited(n ,false);
       unordered_set<int> seen;
        queue<int>q;
        q.push(0);
        visited[0]=true;
        int stepsCount=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)

            {
              int   i =q.front();
              q.pop();
                    //base case
                    if(i==n-1)
                    {
                        return stepsCount;
                    }
                    //go backward
                    if(i-1>=0 && !visited[i-1])
                    {
                        q.push(i-1);
                        visited[i-1]=true;
                    }
                    //go front
                    if(i+1<n && !visited[i+1])
                    {
                        q.push(i+1);
                        visited[i+1]=true;
                    }
                    if(!isPrime[nums[i]] || seen.count(nums[i]))
                    {
                        continue;
                    }

                    //important case if nums[i] is a prime no
                     for(int multiples=nums[i] ;multiples<=maxElement ;multiples+=nums[i])
                     { 
                     //if particular multiple doesnt exist then  continue loop and check for next multiple
                        if(!mp.contains(multiples))
                        {
                            continue;
                        }
                        //ifmultiple exist then  go to its all occurence .
                        for(auto &it: mp[multiples])
                        {
                            if(!visited[it])
                            {
                            q.push(it);
                            visited[it]=true;
                            }
                        }
                     }
                     seen.insert(nums[i]);

            }
            stepsCount++; 
        }
        return stepsCount;
        
    }
};