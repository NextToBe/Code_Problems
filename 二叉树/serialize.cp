#include <iostream>
#include <queue>
#include <string>

using namespace std;

/*
 题目描述：
   序列化和反序列化一个二叉树
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
    string serialize(TreeNode* root) {
        if (!root) {
            return "# ";
        }
        // 按照层级序列化
        string res = "";
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            res += to_string(node->value) + " ";
            if (node->left) {
                res += to_string(node->left->value) + " ";
                que.push(node->left);
            } else {
                res += "# ";
            }
            
            if (node->right) {
                res += to_string(node->right->value) + " ";
                que.push(node->right);
            } else {
                res += "# ";
            }
        }
        
        return res;
    }
    
};
