#include<bits/stdc++.h>
using namespace std;

class findSafeNode
{
private:
    /* data */
public:
   vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int n =  graph.size();
       vector<vector<int>>adj(n);
       vector<int>indegree(n);
       for (int  i = 0; i < n; i++)
       {
        int size = graph[i].size();
        for(int j = 0 ; j<size;j++){
            int node = graph[i][j];
            adj[node].push_back(i);
            indegree[i]++;
        }
       }
       queue<int>q;
       for(int i = 0 ; i<n;i++){
        if(indegree[i] ==0) q.push(i);
       }

       vector<int> res;
       while (!q.empty())
       {
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(auto it :adj[node]){
            indegree[it]--;
            if(indegree[it] ==0) q.push(it);
        }
       }
       sort(res.begin(),res.end());
       return res;
    }
};

