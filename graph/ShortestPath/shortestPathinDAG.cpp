#include<bits/stdc++.h>
using namespace std;

class shortestPathinDAG
{
private:
    /* data */
    void dfs(vector<vector<pair<int,int>>> & adj,int src,vector<bool>&vis,stack<int>&st){
        vis[src] = true;
        
        for(auto it: adj[src]){
            int node = it.first;
          
            if(!vis[node]){
                dfs(adj,node,vis,st);
            }
        }
        st.push(src);
        return ;
    }
   
public:
    vector<int> shortestPath(int src,vector<vector<pair<int,int>>>& adj){
        int n = adj.size();
        vector<int>distance(n,INT_MAX);
        stack<int>st;
        vector<bool>vis(n,false);

        for(int i = 0 ; i<n;i++){
            if(!vis[i]) dfs(adj,i,vis,st);
        }   
        distance[src] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            for (auto it : adj[node]) {
                int neighbor = it.first;
                int weight = it.second;
                if (distance[node] + weight < distance[neighbor]) {
                    distance[neighbor] = distance[node] + weight;
                }
            }
        }
        return distance;
    }
    
};

