#include <bits/stdc++.h>
using namespace std;
class Union{
    public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int a1 = a.size();
        int a2 = b.size();
        vector<int> ans;
        int i = 0, j = 0;
    
        while (i < a1 && j < a2) {
            if (a[i] < b[j]) {
                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }
                i++;
            } else if (a[i] > b[j]) {
                if (ans.empty() || ans.back() != b[j]) {
                    ans.push_back(b[j]);
                }
                j++;
            } else { // If both elements are equal
                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }
                i++;
                j++;
            }
        }
    
        // Add remaining elements from array `a`
        while (i < a1) {
            if (ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
        }
    
        // Add remaining elements from array `b`
        while (j < a2) {
            if (ans.empty() || ans.back() != b[j]) {
                ans.push_back(b[j]);
            }
            j++;
        }
    
        return ans;
    }
    
};