#include <bits/stdc++.h>
using namespace std;

class Celebrity
{
private:
    /* data */
public:
int celebrity(vector<vector<int>> &mat){
        int n = mat.size();

        vector<int>knowme(n);
        vector<int>iknow(n);
        for(int i = 0 ; i<n;i++){
            for (int j = 0; j<n; j++)
            {
                /* code */
                if(mat[i][j] ==1){
                    knowme[j]++;
                    iknow[i]++;
                }
            }
        }
        for(int i = 0 ; i<n;i++){
            if(knowme[i] == n-1 && iknow [i] == 0) return i;
        }
        return -1;
}
int celebrityOptimal(vector<vector<int>> &mat){
    int n = mat.size();

    int top = 0,bottom = n-1;

    while(top<bottom)
    {
        /* code */
        if(mat[top][bottom] ==1){
            top++;
        }else if(mat[bottom][top] ==1){
            bottom--;
        }else{
            top++;
            bottom--;
        }  
        
    }
    if(top>bottom) {return -1;}
        for (int i = 0; i < n; i++)
        {
            if(i == top) continue;  
            /* code */
            if(mat[top][i] ==0 && mat[i][top] ==1) {
                continue;
            }else{
                return -1;
            };
        }

    
    return top;
}
};


