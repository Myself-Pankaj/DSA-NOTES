#include <bits/stdc++.h>
using namespace std;

class SJF{
    private:
    
    public:
    int shortestJobFirst(vector<int>& task){
        int n = task.size();
        sort(task.begin(),task.end());
        int wtTime = 0;
        int endTime = 0;

        for(int i = 0 ; i<n;i++){
            wtTime = wtTime+endTime;
            endTime +=task[i];
        }
        return wtTime/n;
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        int jobsPerfomed = 0;
        int max_profit = 0;
        vector<pair<int,int>>mpp;
        int size = INT_MIN;

        for(int i = 0 ; i<n;i++){
          mpp.push_back({profit[i],deadline[i]});
          if(deadline[i]>size){
            size = deadline[i];
          }
        }
        sort(mpp.begin(),mpp.end(),[](pair<int,int> &a, pair<int,int> &b){
            return a.first>b.first;
        });
        vector<int>scheduling(size+1,-1);

        for(int i = 0 ; i<n;i++){
            
            if(scheduling[mpp[i].second-1] == -1){
                scheduling[mpp[i].second-1] = i;
                max_profit += mpp[i].first;
                jobsPerfomed++;
            }else{
                int j = mpp[i].second-1;
                while(j > 0 && scheduling[j] != -1){
                    j--;
                }
                if(scheduling[j] == -1){
                    scheduling[j] = i;
                    max_profit += mpp[i].first;
                    jobsPerfomed++;
                }
                
            }
            
        }
        return {jobsPerfomed,max_profit};

    }
};