#include<bits/stdc++.h>
using namespace std ;

class cheapestFlight
{
private:
    /* data */
public:
    int findCheapestPrice(int n, vector<vector<pair<int,int>>>& adj, int src, int dst, int k) {
        vector<int>distance(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        distance[src] = 0;
        while (!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();
            for(auto it : adj[node]){
                int adjnode = it.first;
                int f_price = it.second;
                if(f_price+price<distance[adjnode] && stops+1<=k+1){
                    distance[adjnode] = f_price+price;
                    q.push({stops+1,{adjnode,f_price+price}});
                }
            }
        }
        return distance[dst];
    }
};


