#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

/*
 题目描述：
    给定一个二叉树的某个节点 node， 找到该节点的后继节点, 在二叉树的中序遍历序列中，node 的下一个节点叫做后继节点。

*/


// 二叉树的定义如下:
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
};

/*----------------------------------------------------------------------------------*/


class Solution {
public:
    TreeNode* getNextNode(TreeNode* node) {
        if (!node) {
            return nullptr;
        }
        
        if (node->right) {
            return getMostLeft(node->right);
        }
        
        TreeNode* parent = node->parent;
        while(parent && parent->left != node) {
            parent = parent->parent;
        }
        
        return parent;
    }
    
    TreeNode* getMostLeft(TreeNode* node) {
        if (!node) {
            return nullptr;
        }
        
        while (node->left) {
            node = node->left;
        }
        
        return node;
    }
    
};

