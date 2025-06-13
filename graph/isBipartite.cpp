#include<bits/stdc++.h>
using namespace std;

class isBipartite
{
private:
    /* data */
    bool isBipartiteDFSHelper(vector<vector<int>>& adj,int src,int col,vector<int>&color){
        color[src] = col;
        int size = adj[src].size();
        for (int i = 0; i < size; i++)
        {
            int node = adj[src][i];
            if(color[node] == -1){
            if(!isBipartiteDFSHelper(adj, node,!col,color)) return false;
            }
            else if(color[src] == color[node]) return false;
        }
        return true;
    }   
    bool isBipartiteBFSHelper(vector<vector<int>>& adj,int src,int col,vector<int>&color){
        queue<pair<int,int>>q;
        q.push({src,col});
        while (!q.empty())
        {
            int node = q.front().first;
            int coloring = q.front().second;
            q.pop();
            for (int i = 0; i < adj[node].size(); i++)
            {
                int adjnode = adj[node][i];
                if(color[adjnode] == -1){
                    color[adjnode] = !coloring;
                    q.push({adjnode,!coloring});
                }else if(color[adjnode] == coloring) return false;
            }
            
        }
        return true;
    }  
public:
    bool isBipartiteBFS(int nodes,vector<vector<int>>& adj){
        
        vector<int>color(nodes,-1);
        for (int i = 0; i < nodes; i++)
        {
            if(color[i]==-1){
                if(!isBipartiteBFSHelper(adj,i,0,color)) return false;
            }
        }
        return true;
    }
    bool isBipartiteDFS(int nodes,vector<vector<int>>& adj){
        // int n = adj.size();
        vector<int>color(nodes,-1);
        for(int i = 0 ; i<nodes;i++){
            if(color[i] == -1){
                if(!isBipartiteDFSHelper(adj,i,0,color)) return false;
            }
        }
        return true;
    }
};

