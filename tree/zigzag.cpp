#include<bits/stdc++.h>
using namespace std;
#include "treenode.cpp"

class zigzag
{
private:
    /* data */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        int ctr = 0;bool flag = true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            if(ctr %2 !=0) flag = false;
            else flag = true;
            ctr++;
            vector<int>temp;
            for(int i = 1 ; i<=n;i++){
                TreeNode*node = q.front();
                temp.push_back(node->val);
                q.pop();
                    if(node->right){
                        q.push(node->right);   
                    }
                     if(node->left){
                        q.push(node->left);
                    }
                    
                
            }
            if(flag) reverse(temp.begin(),temp.end());
            res.push_back(temp);
        }
        return res;
    }
    
};


