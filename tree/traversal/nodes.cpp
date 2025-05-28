#ifndef TREENODE_H
#define TREENODE_H


class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val = value;
        left = nullptr;
        right = nullptr;   
    }

};

#endif 