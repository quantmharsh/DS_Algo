// //Leetcode:1406. Stone Game III
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

// Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

// The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

// The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

// Assume Alice and Bob play optimally.

// Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.

 

// Example 1:

// Input: stoneValue = [1,2,3,7]
// Output: "Bob"
// Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.
// Example 2:

// Input: stoneValue = [1,2,3,-9]
// Output: "Alice"
// Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
// If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
// If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
// Remember that both play optimally so here Alice will choose the scenario that makes her win.
// Example 3:

// Input: stoneValue = [1,2,3,6]
// Output: "Tie"
// Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.
 

// Constraints:

// 1 <= stoneValue.length <= 5 * 104
// -1000 <= stoneValue[i] <= 1000

class Solution {
public:
    //Approach :Using Recursion+ Memoization
    //its a single dp question because only 1 variable change is required .
    //here we are trying to find best answer if startig from index i
    //both of them have 3 options 
    //1. pick index i then  - solve(i+1)
    //2. pick index i ,i+1 then  -solve(i+2 )
    //3. pick index i , i+1 , i+2  then -solve(i+3)
    //store max of all this 
    //we are storing Maximum score difference (Current Player − Opponent) starting from index i.
   vector<int> dp;
   int n;
   int solve(int i ,vector<int>& stoneValue)
   {
    if(i==n)
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    dp[i]=stoneValue[i]-solve(i+1 ,stoneValue);
    if(i+1<n)
    {
        dp[i]=max(dp[i] ,stoneValue[i]+stoneValue[i+1]-solve(i+2 ,stoneValue));
    }
    if(i+2<n)
    {
        dp[i]=max(dp[i] ,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2] -solve(i+3 , stoneValue) );
    }

    return dp[i];

    
   }
    string stoneGameIII(vector<int>& stoneValue) {
         n=stoneValue.size();
      dp.resize(n+1 ,-1);
         int diff=solve(0 ,stoneValue);
          if(diff < 0)
            return "Bob";
        else if(diff > 0)
            return "Alice";
        
        return "Tie";
        
    }
};