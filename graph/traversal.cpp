#include<bits/stdc++.h>
using namespace std;

class traversal
{
private:
    /* data */
    void dfs(vector<vector<int>>&adj,vector<bool>&vis,int node,vector<int>&list){
        vis[node] = true;
        list.push_back(node);
        for (int  i = 0; i < adj[node].size(); i++)
        {
            /* code */
            if(!vis[adj[node][i]])dfs(adj,vis,adj[node][i],list);
        }
        
    }
public:
    vector<int> bfsinGRAPH(vector<vector<int>>&adj){
        vector<int>bfs;
        int n = adj.size();
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(1);
        visited[1] = true;

        while(!q.empty()){
            int size= q.size();
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(int i = 0 ; i<adj[node].size();i++){
                int neb = adj[node][i];
                if(!visited[neb]){
                    visited[neb] = true;
                    q.push(neb);
                }
            }
        }
        return bfs;
    }
    vector<int> dfsinGRAPH(vector<vector<int>>&adj){
        int n = adj.size();
        vector<int>list;vector<bool>vis(n,false);
        dfs(adj,vis,1,list);
        return list;
    }
};

