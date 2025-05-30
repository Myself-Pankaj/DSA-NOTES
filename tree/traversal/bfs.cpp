#include<bits/stdc++.h>
using namespace std;
#include "nodes.cpp"
class bfs
{
private:
    /* data */
public:

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    if(root == nullptr){
        return ans;
    }
    queue<TreeNode*>q;
    q.push(root);

    while (!q.empty())
    {
        

        int n = q.size();
        vector<int>res;
        for (int i = 0; i < n; i++)
        {
            /* code */
            TreeNode* node = q.front();
            q.pop();

            res.push_back(node->val);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        ans.push_back(res);
        

    }
    return ans;
}
    
};


