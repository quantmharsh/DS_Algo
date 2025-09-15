class Solution {
public:
// kane's Algo(Topo Sort)
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

    unordered_map<int , vector<int>> adjList;
    vector<int> indegree(numCourses , 0);
       for(auto it: prerequisites)
       {
            int u =it[0];
            int v=it[1];
            adjList[u].push_back(v);
            indegree[v]++;
       }
       queue<int>q;
       for(int  i =0;i<numCourses ;i++)
       {
            if(indegree[i]==0)
            {
                q.push(i);
            }
       }
       unordered_map<int , unordered_set<int>> mp;
       while(!q.empty())
       {
        int node= q.front();
        q.pop();
        for(auto it: adjList[node])
        {
            mp[it].insert(node);
            //also store  mp[node ] values(a->b->c=a->c)
            for(auto preq: mp[node])
            {
                mp[it].insert(preq);
            }
            
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
       }

       int Qsize=queries.size();
       vector<bool> result(Qsize ,false);
       for(int  it=0;it<Qsize;it++)
       {
        int src=queries[it][0];
        int dest=queries[it][1];
        bool isreachable= mp[dest].contains(src);
        result[it]=isreachable;
       }
       return result;


        
    }
};