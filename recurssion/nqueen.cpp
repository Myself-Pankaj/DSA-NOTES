#include <bits/stdc++.h>
using namespace std;

class nqueen{
    private:
    bool issafe(int row, int col, vector<string>& board, int n) {
        int dup_row = row, dup_col = col;

        // Check upper diagonal (north-west)
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = dup_row;
        col = dup_col;

        // Check lower diagonal (south-west)
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        row = dup_row;
        col = dup_col;

        // Check left column
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        return true;
    }
    void solve(int n,int col,vector<vector<string>> &res,vector<string>& board){
        if(col == n){
            res.push_back(board);
            return ;
        }
        for(int row = 0 ; row<n;row++){
            if(issafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(n,col+1,res,board);
                board[row][col] = 'X';
            }
        }
    }
    void solve_optimal(int n,int col,vector<vector<string>> &res,
        vector<string>& board,vector<int>&upd,vector<int>&lwd ,vector<int>&lr){
        if(col == n){
            res.push_back(board);
            return ;
        }
        for(int row = 0;row<n;row++){
            if(upd[(n-1)+ (col-row)] == 0 && lwd[row+col] == 0 && lr[row] == 0){
                upd[(n-1)+ (col-row)] = 1;
                lwd[row+col] = 1;
                lr[row] = 1;
                board[row][col] ='Q';
                solve_optimal(n,col+1,res,board,upd,lwd,lr);
                upd[(n-1)+ (col-row)] = 0;
                lwd[row+col] = 0;
                lr[row] = 0;
                board[row][col] ='X';

            }
        }
    }
    public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string> board(n);
        string s(n,'X');

        for(int i = 0 ; i<n;i++){
            board[i] = s;
        }
        solve(n,0,res,board);
        return res;
    }
    vector<vector<string>> solveNQueensOptimally(int n) {
        vector<vector<string>>res;
        vector<string> board(n);
        string s(n,'X');
        vector<int>upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1);
        vector<int>leftRow(n,0);
        for(int i = 0 ; i<n;i++){
            board[i] = s;
        }
        solve_optimal(n,0,res,board,upperDiagonal,lowerDiagonal,leftRow);
        return res;
    }
};