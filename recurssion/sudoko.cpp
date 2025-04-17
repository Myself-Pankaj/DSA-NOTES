#include <bits/stdc++.h>
using namespace std;
class Sudoko{
    private:
    bool solveSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++)
        {
            /* code */
            for(int j = 0 ; j<col;j++){
                if(board[i][j] == '.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isValid(board,i,j,ch)){
                            board[i][j] = ch;
                            if(solveSudoku(board) ==true){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board,int row,int col,char ch){
        for(int i = 0 ; i<9;i++){
            //column
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;
            int drow = 3*(row/3)+i/3;
            int dcol = 3*(col/3)+i%3;
            if(board[drow][dcol] == ch) return false;

        }
        return true;
    }
    public:
    void validSudoko(vector<vector<char>>& board){
        
        solveSudoku(board);
      
    }
};