// //Leetcode : 839.Similar String Groups
// Two strings, X and Y, are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string X.

// For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

// Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

// We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

 

// Example 1:

// Input: strs = ["tars","rats","arts","star"]
// Output: 2
// Example 2:

// Input: strs = ["omv","ovm"]
// Output: 1
 

// Constraints:

// 1 <= strs.length <= 300
// 1 <= strs[i].length <= 300
// strs[i] consists of lowercase letters only.
// All words in strs have the same length and are anagrams of each other.


class Solution {
public:
    // will be using DSU concept if difference in position is less then =2 then same group/parent . otherwise different group
    //at last return total group counts 
    vector<int>parent;
    vector<int>rank;
    int find(int x  )
    {
        if(x==parent[x])
        {
            return x;
        }
        return find(parent[x]);

    }
    void unionByRank(int x , int y )
    {
        int x_parent=find(x);
        int y_parent=find(y);
        if(rank[x_parent]>rank[y_parent])
        {
            parent[y_parent]=x_parent;
           
        }
        else if(rank[y_parent]>rank[x_parent])
        {
            parent[x_parent]=y_parent;
           
        }
        else{
            parent[y_parent]=x_parent;
            rank[x_parent]++;
            
        }
    }
    bool  isSimilar(string str1  , string str2)
    {
        int n =str1.length();
        int cnt=0;
        for(int i =0;i< n;i++)
        {
            if(str1[i]!=str2[i])
            {
                cnt++;
            }
        }
        return cnt==2 || cnt==0;

    }

    int numSimilarGroups(vector<string>& strs) {
        int n =strs.size();
        parent.resize( n ,0);
        rank.resize(n , 0);
        for(int i =0;i< n;i++)
        {
            parent[i]=i;
        }
    int groups=n;
        for(int i =0;i<n;i++)
        {
            for(int j =i+1;j<n;j++)
            {
                if(isSimilar(strs[i] , strs[j]) && find(i)!=find(j))
                {
                    groups--;
                    unionByRank(i , j);
                }
            }
        }
        return groups;


    }
};