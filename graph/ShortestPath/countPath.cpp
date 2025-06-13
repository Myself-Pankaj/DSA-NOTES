#include<bits/stdc++.h>
using namespace std;

class countPath
{
private:
    /* data */
public:
    int countPaths(int n, vector<vector<pair<int,int>>>&adj) {
        vector<int>distance(n,1e9);
        vector<int>ways(n,0);
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;
        distance[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int adjnode = it.first;
                int curr_dis = it.second;
                if(curr_dis+dist< distance[adjnode]){
                    distance[adjnode] = curr_dis+dist;
                    ways[adjnode] = ways[node];
                    pq.push({curr_dis+dist,adjnode});
                }else if(curr_dis+dist == distance[adjnode]){
                    ways[adjnode]= ways[node]+ways[adjnode];
                }
            }
        }
        return ways[n-1];
    }
};


