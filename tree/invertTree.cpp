#include "treenode.cpp"
#include <bits/stdc++.h>
using namespace std;

class invertTree
{
private:
    /* data */
public:
    TreeNode* invertaTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            TreeNode *newleft = nullptr;
            TreeNode *newright = nullptr;
            q.pop();
            if(node->left){
                newright = node->left;
                q.push(newright);
            }
            if(node->right){
               newleft = node->right;
                
                q.push(newleft);
            }
            node->left = newleft;
            node->right = newright;
        }
        return root;
    }
};


