#include<bits/stdc++.h>
using namespace std;

class distinctIsland
{
private:

    /* data */
    string bfs(vector<vector<int>>& grid ,vector<vector<bool>>&vis ,int r,int c){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({r,c});
        string res = "";
        int base_r = r,base_c = c;
        vis[r][c] = true;
        int drow[] = {-1,0,1,0};//upper,right,bottom,left
        int dcol[] = {0,1,0,-1};
        vector<pair<int, int>> shape;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            shape.push_back({row-base_r,col-base_c});
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                /* code */
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] &&grid[nrow][ncol] ==1){
                    vis[nrow][ncol] = true;
                    
                    q.push({nrow,ncol});
                }
            }
            
        }
        sort(shape.begin(),shape.end());
        for (auto& p : shape) {
        res += to_string(p.first) + "_" + to_string(p.second) + "|";
        }
        return res;
    }
   
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        unordered_set<string>st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                /* code */
                if(grid[i][j] == 1 && !vis[i][j]){
                    string res = bfs(grid,vis,i,j);
                    st.insert(res);
                  
                }
            }
        }
        
        return st.size();
    }
};

