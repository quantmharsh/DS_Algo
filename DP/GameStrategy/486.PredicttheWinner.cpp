// //Leetcode:486. Predict the Winner
// Medium
// Topics
// premium lock icon
// Companies
// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

 

// Example 1:

// Input: nums = [1,5,2]
// Output: false
// Explanation: Initially, player 1 can choose between 1 and 2. 
// If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
// So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
// Hence, player 1 will never be the winner and you need to return false.
// Example 2:

// Input: nums = [1,5,233,7]
// Output: true
// Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
// Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
 

// Constraints:

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 107

class Solution {
public:
    //Approach: Using recursion+Memoization
    //this is a game based question in which we need to follow some rules
    //when it is our turn then take the max but when its opposition turn  expext the worst ans
    //in this case worst means opponent pick higher value and left us with lower value
    //so  consider min that we can pick when its our turn again
    //when player 1 pick ith index then player2 can pick i+1 or j  so we left with solve(i+2, j) (when p2 picks i+1) or(i+1 , j-1) (p2 picks j)
    //take min in both case because p2 wil chhoose best answer
     
    int dp[20][20];
    int  Solve( int i , int  j , vector<int>&  nums)
    {
    //base case 
     if( i>j)
     {
        return 0;
     }
     if(i==j)
     {
        return nums[i];
     }
     if(dp[i][j]!=-1)
     {
        return dp[i][j];
     }
                    //p2  -> i+1 or j   p1->i+2 ,j-1
        int take_left= nums[i]+min(Solve(i+2 , j , nums) , Solve(i+1 ,j-1 , nums));
                    //p2 -> j-1  or i   p1->j-2, i+1
        int take_right= nums[j]+min(Solve(i, j-2 , nums) , Solve(i+1 ,j-1 , nums));

        return dp[i][j]=max(take_left , take_right);

    }

    bool predictTheWinner(vector<int>& nums) {
    int n= nums.size();
    memset(dp , -1 ,sizeof(dp));
    int total_score= accumulate(nums.begin() , nums.end() ,0);
    int player1_score=Solve(0 , n-1 , nums);
    int player2_score=total_score-player1_score;
    return player1_score>=player2_score;


        
    }
};