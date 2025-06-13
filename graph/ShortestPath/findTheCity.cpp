#include<bits/stdc++.h>
using namespace std;

class findTheCity
{
private:
    /* data */
    void algo(int src,int th,vector<vector<pair<int,int>>> &adj, vector<vector<int>>&cities){
        int n = cities.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int>distance(n,1e9);
        pq.push({0,src});
        distance[src] = 0;
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int adjnode = it.first;
                int edgewt = it.second;
                if(  dist+edgewt < distance[adjnode]){
                    distance[adjnode] = dist+edgewt;
                    pq.push({dist+edgewt,adjnode});
                }
            }
        }
        
        for(int i = 0 ; i<n;i++){
            // cout<<distance[i]<<" ";
            
            if(src !=i &&distance[i]<=th){
                cities[src].push_back(i);
            }
        }
        // cout<<endl;
    }
public:
    int findTheNebCity(int n, vector<vector<pair<int,int>>> &adj, int distanceThreshold) {
        vector<vector<int>>cities(n);
        for(int i = 0 ; i<n;i++){
            algo(i,distanceThreshold,adj,cities);
        }
        int mini = INT_MAX; int city = -1;
        for (int i = 0; i < n; i++)
        {
            int size = cities[i].size();
            if(size<mini){
                mini = size;
                city = i;
            }else if(size<=mini){
                city=i;
            }
        }
        
        return city;
    }
};


