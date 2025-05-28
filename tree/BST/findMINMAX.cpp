#include <bits/stdc++.h>
#include "nodes.cpp"
using namespace std;

class findMINMAX
{
private:
    /* data */
    TreeNode* findmini(TreeNode* root) {
        if (!root) return nullptr;
        while (root->left) {
            root = root->left;
        }
        return root;
    }

    TreeNode* findmaxi(TreeNode* root) {
        if (!root) return nullptr;
        while (root->right) {
            root = root->right;
        }
        return root;
    }
public:
    vector<pair<TreeNode*, TreeNode*>> findMinMax(TreeNode* root) {
        TreeNode* mini = findmini(root);
        TreeNode* maxi = findmaxi(root);
        return { {mini, maxi} };
    }
};

