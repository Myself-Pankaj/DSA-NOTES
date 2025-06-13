#include<bits/stdc++.h>
using namespace std;

class noofprovince 
{
private:
    /* data */
    void bfs(vector<vector<int>>&adj,vector<bool>&vis,int node){
        
        queue<int>q;
        q.push(node);
        vis[node] = true;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            for (int i = 0; i < adj[top].size(); i++)
            {
                /* code */
                if(!vis[adj[top][i]]){
                    q.push(adj[top][i]);
                    vis[adj[top][i]] = true;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i = 0 ; i<n;i++){
            for(int j = 0; j<isConnected[i].size();j++){
                if(isConnected[i][j] ==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<bool>visited(n,false);int ctr = 0;
        for(int i = 0; i<n;i++){
            if(!visited[i]){
                ctr++;
                bfs(adj,visited,i);
            }
        }
        return ctr;
    }
};

