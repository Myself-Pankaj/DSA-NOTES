#include<bits/stdc++.h>
using namespace std;
#include "treenode.cpp"

class heightOfTree
{
private:
    /* data */
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root) return 0;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int n = q.size();
            depth++;
            for(int i = 0 ; i<n;i++){
                TreeNode*node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return depth;
    }
    int maxDepthRecursive(TreeNode* root) {
        if(!root) return 0;
        int lh = maxDepthRecursive(root->left);
        int rh = maxDepthRecursive(root->right);

        return max(lh,rh)+1;
    }
};

