#include "treenode.cpp"
#include <bits/stdc++.h>
using namespace std;

class symetricTree
{
private:
    /* data */
public:
 bool isSymmetric(TreeNode* root) {
    if(root->left ==nullptr && root->right ==nullptr) return true;
    if(root->left ==nullptr || root->right ==nullptr) return false;

    queue<pair<TreeNode*,TreeNode*>>q;
    q.push({root->left,root->right});

    while(!q.empty()){
        TreeNode*n1 = q.front().first;
        TreeNode*n2 = q.front().second;

        q.pop();
        if(n1->val != n2->val) return false;

        if(n1->left && n2->right){
            q.push({n1->left,n2->right});
        }else if( n1->left == nullptr || n2->right ==nullptr) return false;

        if(n1->right && n2->left){
            q.push({n1->right,n2->left});
        }else if( n1->right == nullptr || n2->left ==nullptr) return false;
    }
    return true;
 }
};



