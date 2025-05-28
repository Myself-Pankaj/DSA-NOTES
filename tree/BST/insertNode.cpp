#include <bits/stdc++.h>
#include "nodes.cpp"
using namespace std;

class insertNode
{
private:
    /* data */
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode = new TreeNode(val);
        if(!root) return newnode;
        TreeNode*curr = root;
        TreeNode*prev = nullptr;
        while(curr){
            prev = curr;
            if(curr->val>val){
                curr = curr->left;
            }else if(curr->val<val){
                curr = curr->right;
            }
        }
        if(prev->val>val) prev->left = newnode;
        else prev->right = newnode;
        return prev;
    }
};

