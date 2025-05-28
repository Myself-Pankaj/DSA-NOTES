#include<bits/stdc++.h>
#include "treenode.cpp"
using namespace std;

class rightViewOfTree
{
private:
    /* data */
public:
     vector<int>rightSideView(TreeNode* root) {
        vector<int>res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            res.push_back(q.front()->val);
            for (int i = 0; i < n; i++)
            {
                TreeNode*node = q.front();
                q.pop();
                
                if(node->right){
                    q.push(node->right);
                }
                if(node->left){
                    q.push(node->left);
                }
            }
            
        }
        return res;
    }
};

