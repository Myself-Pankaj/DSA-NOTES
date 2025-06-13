#include<bits/stdc++.h>
using namespace std;

class googleInterview
{
private:
    /* data */
    vector<int>bfs(vector<vector<int>>&adj,int src){
        int n = adj.size();
        vector<int>distance(n,INT_MAX);
        queue<pair<int,int>>q;
        q.push({src,0});
        distance[src] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            for(auto it: adj[node]){
                int totaldist = dist+1;
                if(distance[it]>totaldist){
                    distance[it] = totaldist;
                    q.push({it,totaldist});
                }
            }
        }
        return distance;
    }
public:
    int aliceBobCabSharing(vector<vector<int>>&adj,int alice,int bob,int dest){
        auto dist_a = bfs(adj,alice);
        auto dist_b = bfs(adj,bob);
        auto dist_d = bfs(adj,dest);
        int mini_dist = INT_MAX;
        int n  = adj.size();
        for(int i = 0 ; i<n;i++){
            int total = dist_a[i]+dist_b[i]+dist_d[i];
            mini_dist = min(mini_dist,total);
        }
        if(mini_dist ==INT_MAX) return -1;
        return mini_dist;
    }
};
