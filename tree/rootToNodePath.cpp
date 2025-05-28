#include<bits/stdc++.h>
using namespace std;
#include "treenode.cpp"

class rootToNodePath
{
private:
    /* data */
bool isLeaf(TreeNode*node){
    if(node->left || node->right) return false;
    return true;
}
void helper(TreeNode*root,vector<int>&ds,vector<vector<int>>&res){
        if(!root) {
            return;
        }
        
        ds.push_back(root->val);
        if(isLeaf(root)){
            res.push_back(ds);
            ds.pop_back(); 
            return;
        }
        helper(root->left,ds,res);
        helper(root->right,ds,res);
        ds.pop_back();

    }
public:
    vector<vector<int>> allRootToLeaf(TreeNode* root) {
            //your code goes here
        vector<int>ds;
        vector<vector<int>>res;
        helper(root,ds,res);

        return res;
	}
};

