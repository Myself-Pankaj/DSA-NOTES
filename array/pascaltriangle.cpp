#include <bits/stdc++.h>
using namespace std;

class pascalTriangle{
    public:
    //to get Sinngle Element 
    //Formaula nCr
    //n!/r!*(n-r)!
    int generatEle(int n,int r){
        long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
    }
    vector<int>printRow(int r){
        int row =r-1;
        vector<int>ans;
        int ele = 1;
        ans.push_back(ele);
        for(int i = 0 ; i<row;i++){
            ele = ele*(row - i);
            ele = ele/(i+1);
            ans.push_back(ele);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
       for(int i = 1; i<=numRows;i++){
        vector<int>ans = printRow(i);
        triangle.push_back(ans);
       }
       return triangle;
    }
};