#include<bits/stdc++.h>
using namespace std;

class networkDelayTime
{
private:
    void createAdjList(vector<vector<int>>& times,vector<vector<pair<int,int>>> &adj){
        int n = times.size();
        for(int i = 0 ; i<n;i++){
            int src = times[i][0];
            int dest = times[i][1];
            int dist = times[i][2];

            adj[src].push_back({dest,dist});
        }
    }
public:
   int networkDelayTimesol(vector<vector<pair<int,int>>> &adj, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // vector<vector<pair<int,int>>> adj(n);
        // createAdjList(times,adj);
        vector<int>distance(n+1,1e9);
        distance[k] = 0;
        pq.push({0,k});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int adjnode = it.first;
                int edgewt = it.second;
                if(dist+edgewt<distance[adjnode]){
                    distance[adjnode] = dist+edgewt;
                    pq.push({dist+edgewt,adjnode});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 0 ; i<n+1;i++){
            if(i!= 0){
                maxi = max(maxi,distance[i]);
            }
        }
        
        return maxi;
    }
};


