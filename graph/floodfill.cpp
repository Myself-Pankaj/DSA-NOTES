#include<bits/stdc++.h>
using namespace std;

class floodfill
{
private:
    /* data */
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int n = img.size();
        int m = img[0].size();

        // }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        queue<pair<int,int>>q;
        int i_color = img[sr][sc];
        q.push({sr,sc});
        img[sr][sc] = color;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>=0 && nrow <n && ncol>=0 && ncol<m && img[nrow][ncol] == i_color){
                    img[nrow][ncol] = color; q.push({nrow,ncol});
                }
            }
            
        }
        return img;
    }
};


