#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

/*
 题目描述：
    给定一个树的根节点 root，判断这棵树是否是完全二叉树
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
    bool isCompleteTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        bool isLeaf = false;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            left = node->left;
            right = node->right;
            
            if ((isLeaf && (left || right)) || (right && !left)) {
                return false;
            }
            
            if (left) {
                que.push(left);
            }
            
            if (right) {
                que.push(right);
            } else {
                isLeaf = true;
            }
            
        }
        
        return true;
    }
    
};

