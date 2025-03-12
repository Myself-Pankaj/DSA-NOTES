#include <bits/stdc++.h>
using namespace std;

class spiralMarrix{
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<int>arr;
        int top = 0; int left = 0; int btm = n-1; int right = m-1;

        while(top<=btm && left<=right){
            for(int i = left;i<= right;i++){
                arr.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top;i<=btm;i++){
                arr.push_back(matrix[i][right]);
            }
            right --;
            if(top<=btm){
                for(int i = right; i>=left;i--){
                    arr.push_back(matrix[btm][i]);
                }
            }
            btm--;

            if(left<=right){
                for(int i = btm;i>=top;i--){
                    arr.push_back(matrix[i][left]);
                }
            }
            left++;
        }

        return arr;
    }
};