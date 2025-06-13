#include<bits/stdc++.h>
using namespace std;

class rottenOrange
{
private:
    /* data */
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        int frestCount = 0;
        vector<vector<bool>> vis(n, vector<bool>(m));
        for (int i = 0; i < n; i++)
        {
            /* code */
            for (int j = 0; j < m; j++)
            {
                /* code */
                if(grid[i][j] ==2){
                    q.push({{i,j},0});
                    vis[i][j] = true;

                }
                if(grid[i][j] ==1){
                    frestCount++;
                }
                if(grid[i][j] ==0){
                    vis[i][j] = true;
                }      
            }
            
        }
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int total_time = 0; int ctr = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            total_time = max(total_time,time);
            for(int i = 0; i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                    && grid[nrow][ncol] ==1 && !vis[nrow][ncol]){
                        q.push({{nrow,ncol}, time+1});
                        vis[nrow][ncol] = true; ctr++;
                }
            }
        }
        if(frestCount != ctr) return -1;

        return total_time;
    }
};


