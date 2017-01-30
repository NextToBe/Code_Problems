#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
 题目描述：
    给定一个树的根节点 root，判断这棵树是否是平衡二叉树, 要求时间复杂度为 O(n)
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
    bool isBalanceTree(TreeNode* root) {
        bool res = true;
        getHeight(root, 1, res);
        return res;
    }
    
    int getHeight(TreeNode* root, int level, bool& res) {
        if (!root) {
            return 0;
        }
        
        int height_left = getHeight(root->left, level + 1, res);
        
        if (!height_left) {
            return level;
        }
        
        int height_right = getHeight(root->right, level + 1, res);
        
        if (!height_right) {
            return level;
        }
        
        if (abs(height_left - height_right) > 1) {
            res = false;
        }
        
        return max(height_right, height_left);
        
    }
};

