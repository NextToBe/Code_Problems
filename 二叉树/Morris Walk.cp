#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 题目描述：
    给定一个二叉树的头结点，完成二叉树的先序，中序，后序遍历，要求时间复杂度 O(N)， 空间复杂度O(1)
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
    // morris 遍历
    
    vector<int> morrisInOrder(TreeNode* root) {
        vector<int> res;

        if (!root) {
            return res;
        }
        
        TreeNode* cur = root;
        TreeNode* node = nullptr;
        
        while (cur) {
            node = cur->left;
            if (node) {
                while (node->right && node->right != cur) {
                    node = node->right;
                }
                if (node->right == nullptr) {
                    node->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    node->right = nullptr;
                }
            }
            res.push_back(cur->value);
            cur = cur->right;
        }
        
        return res;
    }
    
    vector<int> morrisPreOrder(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        
        TreeNode* cur = root;
        TreeNode* node = nullptr;
        while (cur) {
            node = cur->left;
            if (node) {
                while (node->right && node->right != cur) {
                    node = node->right;
                }
                
                if (node->right == nullptr) {
                    node->right = cur;
                    res.push_back(cur->value);
                    cur = cur->left;
                    continue;
                } else {
                    node->right = nullptr;
                }
            } else {
                res.push_back(cur->value);
            }
            
            cur = cur->right;
        }
        
        return res;
    }
    
};
