#include <bits/stdc++.h>
#include "nodes.cpp"
using namespace std;

class recoverBST
{
private:
    /* data */
    TreeNode*first;
    TreeNode*last;
    TreeNode*mid;
    TreeNode*prev;
    void inorder(TreeNode*root){
        if(!root) return ;

        inorder(root->left);
        if(prev  && (root->val<prev->val)){

            if(first == nullptr){
                first = prev;
                mid = root;
            }else{
                last = root;
            }
        }
        prev = root;
        inorder(prev->right);
    }
public:
   void recoverTree(TreeNode* root) {
        first = last= mid = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(last && first) swap(first->val,mid->val);
        else if( first && mid ) swap(first->val,last->val);
    }
};

