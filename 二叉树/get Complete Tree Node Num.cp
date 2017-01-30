#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 题目描述：
    统计完全二叉树的节点数量
 */

// 二叉树的定义如下
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
};

/*----------------------------------------------------------------------------------*/

class Solution {
public:
     int countNodes(TreeNode* root) {
        if (!root) {
             return 0;
        }
         
        int leftmost = 0;
        TreeNode* left = root;
        while (left) {
            leftmost ++;
            left = left->left;
        }
         
        int rightmost = 0;
        TreeNode* right = root;
        while (right) {
            rightmost ++;
            right = right->right;
        }
         
         if (leftmost == rightmost){
             return (1 << leftmost) - 1;
         }
         return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
