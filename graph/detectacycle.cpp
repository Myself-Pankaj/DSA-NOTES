#include<bits/stdc++.h>
using namespace std;

class detectacycle
{
private:
    /* data */
    // Detect a cycle in undirected Graph using DFS 
    bool detect(vector<vector<int>>&adj,vector<bool>&vis,int src,int parent){
        vis[src] = true;
        for(int i = 0 ; i<adj[src].size();i++){
            if(!vis[adj[src][i]]){
            if(detect(adj,vis,adj[src][i],src)) return true;
            }
            else if(adj[src][i] != parent) return true;
        }
        return false;
    }
    
public:
// Detect a cycle in undirected Graph using BFS 
    bool isCycle(vector<vector<int>>&adj){
        int n = adj.size();
        vector<bool>vis(n,false);
        queue<pair<int,int>>q;
        q.push({0,-1});
        vis[0] = true;

        while (!q.empty())
        {
            int node = q.front().first;
            int parent= q.front().second;
            q.pop();
            int size = adj[node].size();
            for(int i = 0; i<size;i++){
                int adj_node = adj[node][i];
                if(!vis[adj_node]){
                    vis[adj_node] = true;
                    q.push({adj_node,node});
                }else if(adj_node != parent){
                    return true;
                }
            }
        }
        return false;
    }
    //This will only work with undirected graph
    bool isCycleDFS(vector<vector<int>>&adj){
        int n = adj.size();
        vector<bool>vis(n,false);
        return detect(adj,vis,0,-1);
    }
    vector<int> findOrder(vector<vector<int>> &adj ,int V){

    }
};


