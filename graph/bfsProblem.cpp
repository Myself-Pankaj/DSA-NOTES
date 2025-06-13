#include <bits/stdc++.h>
using namespace std;

class bfsProblem
{
private:
    /* data */
public:
    //surroundedRegion
    void SurroundedRegions(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i = 0 ; i<n;i++){
            for(int j = 0 ;j <m;j++){
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O'){
                    q.push({i,j});
                    vis[i][j]= true;
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0 ,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0 ; i<4;i++){
                int nrow = row+drow[i];//0 1
                int ncol = col+dcol[i];//1 2

                if(nrow>=1 && nrow<n-1 && ncol>=1 && ncol<m-1 
                    && board[nrow][ncol] =='O' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = true;
                    q.push({nrow,ncol});
                } 
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    // 01 Matrix
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> newmat(n, vector<int>(m, -1));
        // vector<vector<bool>>vis(n,vector<bool>(m,false));

        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    newmat[i][j] = 0;
                }
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            newmat[row][col] = distance;

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    newmat[nrow][ncol] == -1) {
                    newmat[nrow][ncol] = distance + 1;
                    q.push({{nrow, ncol}, distance + 1});
                }
            }
        }
        
        return newmat;
    }
//Number of Enclaves
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i = 0 ; i<n;i++){
            for(int j = 0 ; j<m;j++){
                if((i == 0 || i == n-1 || j ==0 || j == m-1) && grid[i][j] == 1 ){
                    q.push({i,j});
                    vis[i][j]= true;
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0 ; i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && grid[nrow][ncol] ==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol]= true;
                    q.push({nrow,ncol});
                }
            }
        }
        int ctr = 0;
        for(int i = 0 ; i<n;i++){
            for(int j = 0 ; j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1 ){
                    ctr++;
                }
            }
        }
        return ctr;
    }
};

