#include<bits/stdc++.h>
using namespace std;
#include "treenode.cpp"

class maxPathSum
{
private:
    /* data */
    int helper(TreeNode*root,int &maxi){
        if(!root) return 0;
        int lh = helper(root->left,maxi);
        int rh = helper(root->right,maxi);

        maxi = max(lh+rh,maxi);
        int ans = max(lh,rh)+root->val;
        if(ans<0) ans = 0;
    return ans;
    }
public:
   int MaxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int ans = helper(root,maxi);
        return maxi;
    }
};


