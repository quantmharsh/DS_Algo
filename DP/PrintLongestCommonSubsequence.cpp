// //https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383
// // Print Longest Common Subsequence
// Problem statement
// You are given two strings ‘s1’ and ‘s2’.



// Return the longest common subsequence of these strings.



// If there’s no such string, return an empty string. If there are multiple possible answers, return any such string.



// Note:
// Longest common subsequence of string ‘s1’ and ‘s2’ is the longest subsequence of ‘s1’ that is also a subsequence of ‘s2’. A ‘subsequence’ of ‘s1’ is a string that can be formed by deleting one or more (possibly zero) characters from ‘s1’.


// Example:
// Input: ‘s1’  = “abcab”, ‘s2’ = “cbab”

// Output: “bab”

// Explanation:
// “bab” is one valid longest subsequence present in both strings ‘s1’ , ‘s2’.


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 5 6
// ababa
// cbbcad


// Expected Answer:
// "bba"


// Output on console:
// 1


// Explanation of sample output 1:
// “bba” is only possible longest subsequence present in both s1 = “ababa” and s2 = “cbbcad”. '1' is printed if the returned string is equal to "bba". 


// Sample Input 2:
// 3 3
// xyz
// abc


// Expected Answer:
// ""


// Output on console:
// 1


// Explanation of sample output 2:
// There’s no subsequence of ‘s1’ that is also present in ‘s2’. Thus an empty string is returned and '1' is printed.


// Expected Time Complexity:
// Try to solve this in O(n*m). Where ‘n’ is the length of ‘s1’ and ‘m’ is the length of ‘s2’. 


// Constraints:
// 1 <= n, m <= 10^3

// Time Limit: 1 sec


//Approach 1: Bottom Up approach
//We solved lcs question where we find the lcs
//we know that  best answer will be at t[m][n];
//so after  doing lcs.we will start from m ,n and will go backward in 2 possible ways
//if s1[i-1]=s2[j-1] then move diagnoally means in ans push s1[i-1] and reduce i--- ,j--
//if not then check where we have max at t[i-1][j] or t[i][j-1]
//and move in that direction and reduce i-- or j--
string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	


	vector<vector<int>>  t(n+1 ,vector<int>(m+1));
	for(int i=0;i<n+1 ;i++)
	{
		t[i][0]=0;

	}
	for(int i =1;i<m+1;i++)
	{
		t[0][i]=0;
	}

	for(int i =1;i<n+1;i++)
	{
		for(int j =1; j<m+1;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				t[i][j]=1+t[i-1][j-1];
			}
			else {
				t[i][j]=max(t[i-1][j] ,t[i][j-1]);
			}
		}
	}

	string ans="";
	//Now we will start from i=m and j=n since lcs sis stored on t[m][n]
	int i =n;
	int j=m;
	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			ans.push_back(s1[i-1]);
			i--;
			j--;
		}
		else if(t[i-1][j]>t[i][j-1])
		{
			i--;
		}
		else{
			j--;
		}
	}
	reverse(ans.begin() , ans.end());
	return ans;



}