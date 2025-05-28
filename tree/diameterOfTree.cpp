#include<bits/stdc++.h>
using namespace std;
#include "treenode.cpp"

class diameterOfTree
{
private:
    /* data */
    int helper(TreeNode*root,int &maxi){
        if(!root) return 0;
        int lh = helper(root->left,maxi);
        int rh = helper(root->right,maxi);

        maxi = max(lh+rh,maxi);
        return max(lh,rh)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
        int ans = helper(root,maxi);

        return maxi;
    }
};

