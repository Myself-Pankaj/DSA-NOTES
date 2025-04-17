#include<bits/stdc++.h>
using namespace std;

class CookieAssigning{
    public:
    int findContentChildren(vector<int>& gf, vector<int>& cookie) {
        int n = gf.size(),m = cookie.size();
        sort(gf.begin(),gf.end());
        sort(cookie.begin(),cookie.end());
        int i = 0,j = 0;
        while (i<n &&j<m)
        {
            /* code */
            if(gf[i]<=cookie[j]){
               i++;
            }
            j++;
        }
        return  i;
    }
};