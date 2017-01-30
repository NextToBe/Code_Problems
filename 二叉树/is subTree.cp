#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
 题目描述：
    给定两个树的根结点， 判断 t1 树是否完全包含 t2 树的拓扑结构
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
    bool contains(TreeNode* root1, TreeNode* root2) {
        return check(root1, root2) || contains(root1->left, root2) || contains(root1->right, root2);
    }
    
    bool check(TreeNode* root1, TreeNode* root2) {
        if (!root2) {
            return true;
        }
        
        if (!root1 || root1->value != root2->value) {
            return false;
        }
        
        return check(root1->left, root2->left) && check(root1->right, root2->right);

    }
};

