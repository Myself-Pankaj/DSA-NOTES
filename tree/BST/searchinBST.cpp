#include <bits/stdc++.h>
#include "nodes.cpp"
using namespace std;

class searchinBST
{
private:
    /* data */
public:
   TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        TreeNode*node;
        if(root->val == val){
            return root;
        }
        if(root->val > val){
            node = searchBST(root->left,val);
        }
        if(root->val<val){
            node = searchBST(root->right,val);
        }
        return node;
        
    }
};

