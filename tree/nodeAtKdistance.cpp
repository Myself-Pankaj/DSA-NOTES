#include "treenode.cpp"
#include<bits/stdc++.h>
using namespace std;

class nodeAtKdistance
{
private:
    /* data */
    void parent_marking(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mpp){
        if(!root) return;
        queue<TreeNode*>q;
        q.push(root);
        mpp[root] = root;
        while(!q.empty()){
            int n = q.size();
            TreeNode* p_node = q.front();
            q.pop();
            for (int i = 0; i < n; i++)
            {
                /* code */
                if(p_node->left){
                    q.push(p_node->left);
                    mpp[p_node->left] = p_node;
                }
                if(p_node->right){
                    q.push(p_node->right);
                    mpp[p_node->right] = p_node;
                }
            }
        }
    }
public:
   vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*>parentNode;
        parent_marking(root,parentNode);
        unordered_map<TreeNode*,bool>visited;
        vector<int>res;
        queue<TreeNode*>q;
        q.push(target);
        int ctr =0;
        while(!q.empty()){
            int n = q.size();
            ctr++;
            if(ctr ==k+1) break;
            for (int i = 0; i < n; i++)
            {
                TreeNode*node = q.front();
                q.pop();
                visited[node] = true;
                /* code */
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                }
                if(node->right&& !visited[node->right] ){
                    q.push(node->right);
                }
                if(parentNode[node] && !visited[parentNode[node]]){
                    q.push(parentNode[node]);
                }
            }
        }

        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};


