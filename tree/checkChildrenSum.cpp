#include "treenode.cpp"
#include<bits/stdc++.h>
using namespace std;

class checkChildrenSum
{
private:
    /* data */
public:
    bool checkTree(TreeNode* root) {
        if (!root || (!root->left && !root->right))
        return true;
        int leftVal = 0;
        if (root->left) {
            leftVal = root->left->val;
        }

        int rightVal = 0;
        if (root->right) {
            rightVal = root->right->val;
        }

        return (root->val == leftVal + rightVal) && checkTree(root->left) && checkTree(root->right);
    }

};

