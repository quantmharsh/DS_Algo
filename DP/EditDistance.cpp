// //leetcode: 72 . Edit Distance 
// Medium
// Topics
// premium lock icon
// Companies
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
 

// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.

class Solution {
public:
    //Approach 1: Using Recursion+Memoization
    //start from m ,n 
    //we have 3 scenarios and base case is
    //base case
    //if  m==0 then return n //delete
    //if n==0 then return m //insert

    //Insertion:
    //when inserting new character then  m will be same and only n will reduce to n-1
    //Deletion:
    //when deleting existing character from s1 then m will reduce to m-1 and n will be same
    //Replace
    //then move m to m-1 and n to n-1
    //Since 2 variables are changing we will have 2d dp t[m][n]
    //at last return t[m][n] 
    int t[501][501];
    int solve(string &word1 , string &word2  , int m , int n)
    {
        if(m==0 || n==0)
        {   
            cout<<"reached here"<<endl;
            return m+n;
        }
        if(t[m][n]!=-1)
        {    cout<<"m:"<<m<<"n:"<<n<<endl;
            cout<<t[m][n]<<endl;
            return t[m][n];
        }
        if(word1[m-1]==word2[n-1])
        {
           return  t[m][n]=solve(word1 ,word2 , m-1 , n-1);
        }
        else{
            int insertChar=1+solve(word1 ,word2 , m , n-1);
            int deleteChar=1+solve(word1 ,word2 , m-1 , n);
            int replaceChar=1+solve(word1 , word2 , m-1 , n-1);
            return t[m][n]=min({insertChar , deleteChar , replaceChar});
        }
        return -1;
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n =word2.length();
        memset(t ,-1 , sizeof(t));
        return solve(word1 , word2 , m , n);
        
    }
};




class Solution {
public:
//Approach 2: Using Bottom Up Approach
//start 2 loops fom i =0 to m and j=0 to n
//base condition:
    //if i=0 or j=0 then t[i][j]=i+j;

//if word1[i-1]==word2[j-1] then t[i][j]=1+t[i-1][j-1]
//else  t[i][j]= 1+min({t[i-1][j-1] ,t[i][j-1] ,t[i-1][j]}) //replaceChar , inserchar ,deletecha

    int minDistance(string word1, string word2) {

    int m =word1.length();
    int n =word2.length();
    vector<vector<int>> t(m+1 , vector<int>(n+1));
    for(int i =0;i<=m;i++)
    {
        for(int j =0;j<=n;j++)
        {
            //base conditon
            if(i==0 || j==0)
            {
                t[i][j]=i+j;
        
            }
           else  if(word1[i-1]==word2[j-1])
            {
                t[i][j]=t[i-1][j-1];
            }
            else {
            t[i][j]=1+min({t[i][j-1] ,t[i-1][j] ,t[i-1][j-1]});
            }
        }
    }
    return t[m][n];
        
    }
};