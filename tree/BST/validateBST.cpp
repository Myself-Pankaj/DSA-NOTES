#include <bits/stdc++.h>
#include "nodes.cpp"
using namespace std;

class validateBST
{
private:
    /* data */
    bool helper(TreeNode* root,long long minrange,long long maxrange){
        if(!root) return true;

        if(root->val<=minrange|| maxrange>=root->val) return false;
        return helper(root->left,minrange,root->val) &&
         helper(root->right,root->val,maxrange);
    }
public:
   bool isValidBST(TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}
};


