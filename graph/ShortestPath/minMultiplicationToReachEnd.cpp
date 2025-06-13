#include<bits/stdc++.h>
using namespace std;

class minMultiplicationToReachEnd
{
private:
    /* data */
public:
     int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        queue<pair<int,int>>q;
        vector<int>steps(1e5,1e9);
        q.push({start,0});
        steps[start] = 0;
        while (!q.empty())
        {
            int node = q.front().first;
            int r_steps = q.front().second;
            q.pop();
            for(auto it: arr){
                int num = (it*node) % 100000;
                // if(num == end) return r_steps+1;
                if(r_steps+1<steps[it]){
                    steps[num] = r_steps+1;
                    if(num == end) return r_steps+1;
                    q.push({num,r_steps+1});
                }

            }
        }
        return -1;
    }
};
