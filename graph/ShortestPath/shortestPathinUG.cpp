#include<bits/stdc++.h>
using namespace std;

class shortestPathinUG
{
private:
    /* data */
public:
   vector<int>shortestPath(int src,vector<vector<int>>&adj){
    int n = adj.size();
    vector<int>distance(n,INT_MAX);
    queue<pair<int,int>>q;
    q.push({src,0});
    distance[src] = 0;
    while (!q.empty())
    {
        int node = q.front().first;
        int dis = q.front().second;
        q.pop();
        for(auto it: adj[node]){
            int newdis = dis+1;
            if(distance[it]> newdis){
                q.push({it,newdis});
                distance[it] = newdis;
            }
        }
    }
    return distance;
   }
   int shortestPathFromsrctodestination(int src,int destination,vector<vector<int>>&adj){
        int n = adj.size();
        vector<int>distance(n,INT_MAX);
        queue<pair<int,int>>q;
        q.push({src,0});
        distance[src] = 0;
        while (!q.empty())
        {
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            for(auto it: adj[node]){
                if(distance[it]>dis+1){
                    distance[it] = dis+1;
                    q.push({it,dis+1});
                }
            }
        }
        return distance[destination];
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int distance = 1e9;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        q.push({{0,0},0});
        vis[0][0] = true;
        
        int drow[] = {-1,-1,-1,0,1,1,1,0};
        int dcol[] = {-1,0,1,1,1,0,-1,-1};


        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int i = 0 ; i<4*2;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] == 0){
                    vis[nrow][ncol] = true;
                    if(nrow == n-1 && ncol == n-1 && dist+1<distance){
                        distance = dist+1;
                    }
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }
        return distance;
    }
};

