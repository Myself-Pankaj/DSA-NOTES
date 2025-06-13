#include<bits/stdc++.h>
using namespace std;

class bellmendFord
{
private:
    /* data */
public:
  vector<int> bellmen( vector<vector<int>> &edges,int src){
    int n  = edges.size();
    cout<<n<<endl;
    vector<int>distance(n,1e9);
    
    distance[src] = 0;
    for (int i = 0; i < n; i++)
    {
        for(int j  = 0; j<n;j++){
      int u = edges[j][0];
      int v = edges[j][1];
      int wt = edges[j][2];

      if(distance[u] != 1e9 && distance[u]+wt <distance[v]){
        if(i == n- 1)return {-1};
        distance[v] = distance[u] + wt;
      }
    }
    }
    return distance;
  }
};


