#include<bits/stdc++.h>
using namespace std;
#include "treenode.cpp"

class maxWidthOfTree
{
private:
    /* data */
public:
    int widthOfBinaryTree(TreeNode* root) {
        int width = 0;
        if(!root) return width;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            int mini = q.front().second;
            int firstnode,lastnode;
            for (int i = 0; i < n; i++)
            {
                /* code */
                int curr_ind = q.front().second-mini;
                TreeNode*node = q.front().first;
                q.pop();
                if(i ==0) firstnode = curr_ind;
                if(i ==n-1) lastnode = curr_ind;

                if(node->left){
                    q.push({node->left,2*curr_ind+1});
                }
                if(node->right){
                    q.push({node->right,2*curr_ind+2});
                }

            }
            width = max(width,lastnode-firstnode+1);
        }
        return width;
    }
};

