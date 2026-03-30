// //Leetcode: 1092. Shortest Common Supersequence 
// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

// Example 1:

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation: 
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.
// Example 2:

// Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
// Output: "aaaaaaaa"
 

// Constraints:

// 1 <= str1.length, str2.length <= 1000
// str1 and str2 consist of lowercase English letters.

class Solution {
public:
    //Approach 1: Bottom-up approach
    //firstly find the scss using bottom up approach
    //for scss:
        //start from i=0 till m and  j=0 till n 
        // if i==0 or j==0  then t[i][j]=i+j
        //if s1[i-1]=s2[j-1] then   best  till s1 ith index and s2 jth index wll be 1+t[i-1][j-1]
        //if s1[i-1]!=s2[j-1] then best  till s1 ith index and s2 jth index wll be 1+min(t[i-1][j] ,t[i][j-1])
    //printing scss
        //Approach :Nearly same which we have done in Print Longest common subsequence
        //till here we will get the scss at t[m][n]
        //we will do reverse traversing in matrinx from i=m and j=n
        // check which index have smaller value . because then only we will get scsss
            //if t[i-1][j]<t[i][j-1] then  ans.push_back(S1[i-1]).and i-- else s2[j-1] and j--
            //if both  characters at s1[i-1]==s2[j-1]are equal then ans.push_back(s1[i-1]) and reduce i-- ,j-- .Move diagonally 
    string shortestCommonSupersequence(string str1, string str2) {
        
        int m= str1.length();
        int n =str2.length();
        
        vector<vector<int>> t(m+1 , vector<int>(n+1));
        for(int i =0;i<m+1;i++)
        {
            for(int j =0;j<n+1;j++)
            {
                if(i==0||j==0)
                {
                    t[i][j]=i+j;
                }
               else  if(str1[i-1]==str2[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                }
                else
                {
                    t[i][j]=1+min(t[i-1][j],t[i][j-1]);
                }
            }
        }

        //Print scss
        int  i =m ;
        int j =n;
        string scss="";
        while(i>0 && j>0)
        {

            if(str1[i-1]==str2[j-1])
            {
                scss.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(t[i-1][j]<t[i][j-1])
            {
                scss.push_back(str1[i-1]);
                i--;
            }
            else 
            {
                scss.push_back(str2[j-1]);
                j--;
            }
            
        }

        while(i>0)
        {
            scss.push_back(str1[i-1]);
            i--;
        }
        while(j>0)
        {
            scss.push_back(str2[j-1]);
            j--;
        }

        reverse(scss.begin(),scss.end());
        return scss;



    }
};