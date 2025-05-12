#include <bits/stdc++.h>
using namespace std;

class SlidingWindowMax
{
private:
    /* data */
public:
vector<int> maxSlidingWindowBrute(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> max_total;
        for (int  i = 0; i <= n-k; i++)
        {
            int curr_max = INT_MIN;
            for (int j = i; j < i+k; j++)
            {
                /* code */
                curr_max  = max(curr_max,nums[j]);
            }
            max_total.push_back(curr_max);
        }
        return max_total;
}
vector<int> maxSlidingWindowOptimal(vector<int>& nums, int k) {
    int n = nums.size();
    
    vector<int> max_total;
    deque<int>q;
    for (int  i = 0; i <n; i++)
    {
        //checking range 
        if(!q.empty() && q.back() <= i-k ){
            q.pop_front();
        }
        while (!q.empty() && nums[q.back()] <= nums[i]){
            q.pop_back();
        }
        q.push_back(i);
        if(i>=k - 1)max_total.push_back(nums[q.front()]);
        
    }
    return max_total;
}
};


