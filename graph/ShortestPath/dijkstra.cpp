#include<bits/stdc++.h>
using namespace std;

class dijkstra
{
private:
    /* data */
    
public:

    //Using Priority queue
    vector<int> dijkstraAlgo(int V, vector<vector<pair<int,int>>> &adj, int src) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int>distance(V,1e9);

        pq.push({0,src});
        distance[src] = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int edgewt = it.second;
                int adjnode = it.first;
                if(dist+edgewt<distance[adjnode]){
                    distance[adjnode] = dist+edgewt;
                    pq.push({dist+edgewt,adjnode});
                }
            }
        }
        for(int i = 0 ; i<V;i++){
            if(distance[i] == 1e9) distance[i] = -1;
        }
        return distance;
    }
    //Using Set
    vector<int> dijkstraAlgoUsingSet(int V,  vector<vector<pair<int,int>>> &adj,int src){
        set<pair<int,int>>st;
        vector<int> distance(V,1e9);
        st.insert({0,src});
        distance[src] = 0;
        while(!st.empty()){
           auto it = *st.begin();
           int dist = it.first;
           int node = it.second;
            st.erase(it);
           for(auto i: adj[node]){
            int edgeWt = i.second;
            int adjNode = i.first;
            if (dist + edgeWt < distance[adjNode]) {
                // If the node already exists in the set, remove the older (longer) distance
                if (distance[adjNode] != 1e9) {
                    st.erase({distance[adjNode], adjNode});
                }

                distance[adjNode] = dist + edgeWt;
                st.insert({distance[adjNode], adjNode});
            }
           }

        }
        return distance;    
    }
    
    vector<int>shortestPath(int V,vector<vector<pair<int,int>>> &adj,int src,int dest){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>distance(V,1e9),parent(V);
        for(int i = 0 ;i<V;i++) parent[i] = -1;
        pq.push({0,src});
        distance[src] = 0;
        parent[src] = src;
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int adjnode = it.first;
                int edgewt = it.second;
                if(dist+edgewt <distance[adjnode]){
                    parent[adjnode] = node;
                    distance[adjnode] = edgewt+dist;
                    pq.push({edgewt+dist,adjnode});
                }
            }
        }
        if(distance[dest] == 1e9) return {-1};
        vector<int>path;
        int node = dest;
        //-1 1 1 4 1 3
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(src);
        reverse(path.begin(),path.end());
        return path;
    }
};

