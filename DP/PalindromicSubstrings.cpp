// //Leetcode: 647. Palindromic Substrings
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.

class Solution {
public:
    //Approach 1: Using Recursion+Memoization
    //need to traverse all character with 2 ponters i , j
    //if s[i]==s[j] then  do j-- and i++ . and store t[i][j]=true or false
    //T.C : O(n^2) - Every subproblem is being computed only once and after that it's being reused
    //S.C : O(n^2)
    int t[1001][1001];
    bool checkPalindrome(string &s , int i ,int j)
    {
        //base case
        if(i>=j)
        {
            return true;
        }
       else if(t[i][j]!=-1)
        {
            return t[i][j];
        }
       else  if(s[i]==s[j])
        {
            return t[i][j]=checkPalindrome(s, i+1 ,j-1);
        }
        return t[i][j]= false;

    }
    int countSubstrings(string s) {
        int n =s.length();
        int count =0;
        memset(t , -1 ,sizeof(t));
        for(int i =0;i<n;i++)
        {
            for(int j=i;j<n;j++)    
            {   
                if(checkPalindrome(s , i , j))
                {
                    count++;
                }
            }
        }
        return count;
        
    }
};


class Solution {
public:
    //Approach 2: Bottom Up approach
    //we know that string of 1 length is palindrome
    //so t[i][i]=true or we can say if(i==j)  then t[i][j]=true
    //Scenario 2: String of length 2
    //in this case j=i+1 always. we can say if s[j]==s[i] then t[i][j]=true
    //Scenario 3: String having length >=3
        //we need to check if s[i]==s[j] && t[i+1][j-1]==true .if then t[i][j]=true
        //this means we are storing results in t[i][j] we know value of t[i+1][j-1].
        //if from index i+1 to index j-1 string is palindrromic and s[i]==s[j].so t[i][j] is also   
        //palindrom
    //Traversing:
        //We will traverse for all Lengths(L) from  1 to n
        //inner loop will say from which index we are starting(i) and till which index(j)
        //here j will be j=i+l-1 . For ex. for Length =3 and starting index i =0 the last index
        //(j)     will be j=i+L-1  (0+3-1)=2 => s[2]
    //at last we will check if t[i][j]==true then increase count and return count 

    int countSubstrings(string s) {
        int n =s.length();
        vector<vector<bool>> t(n , vector<bool>(n ,false));
        int count=0;
        for(int L=1;L<=n;L++)
        {
            for(int i =0;i+L-1<n;i++)
            {
               int j=i+L-1;
               if(i==j)
               {
                t[i][j]=true;
               } 
               else if(j==i+1)
               {
                if(s[i]==s[j])
                {
                    t[i][j]=true;
                }
               }

               else{
                
                t[i][j] = (s[i]==s[j]) && (t[i+1][j-1]);

               }

               if(t[i][j]==true)
               {
            //    cout<<"i:"<<i<<","<<"j:"<<j<<endl;
                count++;
               }
            }
        }
    return count;
        
    }
};