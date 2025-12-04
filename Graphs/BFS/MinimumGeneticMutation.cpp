// //Leetcode: 433 .Minimum Genetic Mutation
// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

// Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

// For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
// There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

// Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

// Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

// Example 1:

// Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
// Output: 1
// Example 2:

// Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
// Output: 2
 

// Constraints:

// 0 <= bank.length <= 10
// startGene.length == endGene.length == bank[i].length == 8
// startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].

// Time and Space : 
// Let's suppose with generic case : 
// 1. Length of gene strings = n
// 2. Number of characters we can replace with = m
// 3. Total number of possibilities (nodes) we can have = m^n (because for each of the n characters, there are m options)
// 4. At each node we are doing nested for loop = m*n (Trying m m characters with each n places)

// Assuming inside set operations take constant time, we can have Time = O(m^n * m*n)


// Space : 
// We have taken an unordered set to store bank set (assume it's size is S) = O(S)
// We also took visited set (which could store all possible nodes in worst case) = O(m^n)

// Total = O(S + m^n)

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        unordered_set<string>  bankSet(bank.begin() , bank.end());
        vector<string>visited{};
        queue<string>q;
        int level=0;
        visited.push_back(startGene);
        q.push(startGene);

        while(!q.empty())
        {
            int n =q.size();
            while(n--)
            {
             string node= q.front();
             q.pop();
                 if(node==endGene)
                    {
                        return level;
                    }
             for(char ch:"ACGT")
             {
                for(int i =0;i<node.size();i++)
                {
                    string temp =node;
                    temp[i]=ch;
                  
                
                    //check whether exists in bankSet or not and if present then it should be not visited
                    if(bankSet.find(temp)!=bankSet.end() && find(visited.begin() , visited.end() , temp)==visited.end() )
                    {
                        visited.push_back(temp);
                        q.push(temp);
                    }

                }
             }
            }
            level++;

        }
         return -1;
    }
   
};