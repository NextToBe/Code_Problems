#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

/*
 题目描述：
    给定一个二叉树的根节点 root, 以及这棵树中的两个节点 node1 和 node2，找到这两个节点的最近公共祖先节点。

*/


// 二叉树的定义如下:
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

};

/*----------------------------------------------------------------------------------*/


class Solution {
public:
    TreeNode* getLowestAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2) {
        if (!root || !node1 || !node2) {
            return nullptr;
        }
        
        if (node1 == root || node2 == root) {
            return root;
        }
        
        TreeNode* left = getLowestAncestor(root->left, node1, node2);
        TreeNode* right = getLowestAncestor(root->right, node1, node2);
        
        if (left && right) {
            return root;
        }
        
        return left ? left : right;
    }
};

