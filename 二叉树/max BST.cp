#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
 题目描述：
        给定一个二叉树的头结点，找到含有节点最多的搜索二叉子树。
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

    TreeNode* biggestBST(TreeNode* root) {
        vector<int> record(3, 0);
        return postOrder(root, record);
    }
    
    TreeNode* postOrder(TreeNode* root, vector<int>& record) {
        if (!root) {
            record[0] = 0;
            record[1] = INT_MAX;
            record[2] = INT_MIN;
            return nullptr;
        }
        
        int value = root->value;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        TreeNode* lBST = postOrder(left, record);
        int lSize = record[0], lMin = record[1], lMax = record[2];
        TreeNode* rBST = postOrder(right, record);
        int rSize = record[0], rMin = record[1], rMax = record[2];
        
        record[1] = min(lMin, value);
        record[2] = max(rMax, value);
        
        if (left == lBST && right == rBST && lMax < value && rMin > value) {
            record[0] = lSize + rSize + 1;
            return root;
        }
        
        record[0] = lSize > rSize ? lSize : rSize;
        return lSize > rSize ? lBST : rBST;
        
    }

};
