#include<bits/stdc++.h>
using namespace std;

class astoriodCollision
{
private:
    /* data */
public:
    vector<int> collision(vector<int>&arr){
        int n = arr.size();
        vector<int>list;
        for (int i = 0; i < n; i++)
        {
            /* code */
            if(arr[i]>0)list.push_back(arr[i]);
            else{
                while (!list.empty() && list.back()>0 && list.back()<abs(arr[i]))
                {
                    /* code */
                    list.pop_back();
                }
                if(!list.empty() && list.back() == abs(arr[i])){
                    list.pop_back();
                }else if(list.empty() || list.back()<0){
                    list.push_back(arr[i]);
                }
                
            } 
           
        }
        return list;
    }
};


