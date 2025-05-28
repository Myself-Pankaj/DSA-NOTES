#include<bits/stdc++.h>
using namespace std;
#include "treenode.cpp"

class balanceTreeOrNot
{
private:
    /* data */
    int check(TreeNode * root){
        if(!root) return 0;

        int lh = check(root->right);
        int rh = check(root->left);
        if(abs(lh-rh)>1) return -1;
        if(lh == -1 || rh == -1) return -1;

        return max(lh,rh)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        
        if(!root) return true;
        if(check(root) == -1) return false;
        return true;
    }
};

