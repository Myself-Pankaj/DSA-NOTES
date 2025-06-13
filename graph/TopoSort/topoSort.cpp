#include<bits/stdc++.h>
using namespace std;

class topoSort
{
private:
    /* data */
    void dfs(int node,vector<bool>&vis,vector<vector<int>>&adj,stack<int>&st){
        vis[node] = true;

        for (auto it: adj[node])
        {
            if(!vis[it]) dfs(it,vis,adj,st);
        }
        st.push(node);
        return ;
    }
public:
    vector<int> toposort(int V, vector<vector<int>>&adj){
        int n = adj.size();vector<int>indegree(V);
        queue<int>q;
        for (int  i = 0; i < n; i++)
        {
            int size = adj[i].size();
            for(int j = 0;j<size;j++){
                indegree[adj[i][j]]++;
            }
        }
        
        for(int i = 0;i<V;i++){
            if(indegree[i] ==0) q.push(i);
        }
        vector<int>res;
        while(!q.empty()){
            int node = q.front();
            res.push_back(node);
            q.pop();
            for(int i = 0 ; i<adj[node].size();i++){
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }
        return res;
    }
    vector<int> toposortviadfs(int V, vector<vector<int>>&adj){
        vector<int>res;
        vector<bool>vis(V,false);
        stack<int>st;
        for (int i = 0; i < V; i++)
        {
           if(!vis[i]){
            dfs(i,vis,adj,st);
           }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

