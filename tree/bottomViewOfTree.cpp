#include<bits/stdc++.h>
using namespace std;
#include "treenode.cpp"
class bottomViewOfTree
{
private:
    /* data */
public:
    vector<int> bottomView(TreeNode *root) {
        // Your Code Here
        map<int,int>mpp;
        vector<int>res;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
               TreeNode *node = q.front().first;
               int level = q.front().second;
               mpp[level] = node->val;
               q.pop();
               if(node->left){
                q.push({node->left,level-1});
               }
               if(node->right){
                q.push({node->right,level+1});
               }
            }
        }
        for(auto it:mpp){
            res.push_back(it.second);
        }
        return res;
    }
};

