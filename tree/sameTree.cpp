#include "treenode.cpp"
#include <bits/stdc++.h>
using namespace std;

class sameTree
{
private:
    /* data */
public:
     bool isSameTree(TreeNode* p, TreeNode* q) {
         if(!p && !q) return true;
         if(!p || !q) return false;
        queue<pair<TreeNode*,TreeNode*>>qq;
        qq.push({p,q});

        while (!qq.empty())
        {
            /* code */
            TreeNode *n1 = qq.front().first;
            TreeNode* n2 = qq.front().second;
            qq.pop();
            if(n1->val != n2->val) return false;
            if(n1->left && n2->left){
                qq.push({n1->left,n2->left});
            }
            else if( n1->left || n2->left) return false;

            if(n1->right && n2->right){
                qq.push({n1->right,n2->right});
            }
            else if( n1->right || n2->right) return false;
        }
        return true;
    }
};

