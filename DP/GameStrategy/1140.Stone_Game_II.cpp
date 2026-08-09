// //Leetcode:1140. Stone Game II
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.

// Alice and Bob take turns, with Alice starting first.

// On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

// The game continues until all the stones have been taken.

// Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

 

// Example 1:

// Input: piles = [2,7,9,4,4]

// Output: 10

// Explanation:

// If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
// If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
// So we return 10 since it's larger.

// Example 2:

// Input: piles = [1,2,3,4,5,100]

// Output: 104

 

// Constraints:

// 1 <= piles.length <= 100
// 1 <= piles[i] <= 104

class Solution {
public:
    //Approach : DP Recursion+Memoization
    //3D DP 
    //this is a game strategy question . in this type of question
    //when its our turn then pick the best answer when opponents  turn expect the worst
    //Alice turn add total stoes by picking pile][i] 
    //in bobs turn dont add it because we are calculating answer fr alice not bob
    
    int n ;
    int dp[2][101][101];
    int solve(int i , int player , int M ,vector<int>& piles)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[player][i][M]!=-1)
        {
            return dp[player][i][M];
        }
        int result=player==1?-1:INT_MAX;
        int stones=0;
        for(int x=1;x<=min(n-i, 2*M);x++)
        {
            stones+=piles[x+i-1];
            //alice turn 
            if(player==1)
            {
                result=max(result , stones+solve(i+x , 0 , max(M ,x) , piles));
            }
            //bobs turn
            else{
                result= min(result , solve(i+x , 1, max(M , x),piles));
            }

        } 
     //   cout<<"dp[player][i][M]"<<dp[player][i][M]<<endl;

        return dp[player][i][M]=result;
    
        
    }
    int stoneGameII(vector<int>& piles) {

         n =piles.size();
        memset(dp , -1 , sizeof(dp));

        return solve(0 , 1, 1,piles);
    
        
    }
};