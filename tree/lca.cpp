#include<bits/stdc++.h>
using namespace std;
#include "treenode.cpp"

class lca
{
private:
    /* data */
    void paths(TreeNode* root, TreeNode* p,vector<TreeNode*>&ds,vector<TreeNode*>&ans){
        if(!root) return;

        ds.push_back(root);
        if(root == p){
            ans = ds;
            ds.pop_back();
            return;
        }
        paths(root->left,p,ds,ans);
        paths(root->right,p,ds,ans);
        ds.pop_back();
    }
public:
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2, ds;

        paths(root, p, ds, path1);
        ds.clear(); // clear before finding second path
        paths(root, q, ds, path2);

        TreeNode* res = nullptr;
        int i = 0;

        // Find the last common node in both paths
        while (i < path1.size() && i < path2.size()) {
            if (path1[i] != path2[i]) break;
            res = path1[i];
            i++;
        }
        return res;
    }
    TreeNode* lowestCommonAncestorOptimal(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root) return root;

        if(root == p || root ==q){
            return root;
        }

        TreeNode* left = lowestCommonAncestorOptimal(root->left,p,q);
        TreeNode* right = lowestCommonAncestorOptimal(root->right,p,q);

        if(left == NULL){
            return right;
        }else if(right == NULL){
            return left;
        }else{
            return root;
        }
    }
};


