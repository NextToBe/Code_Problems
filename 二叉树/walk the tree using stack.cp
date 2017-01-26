#include <iostream>
#include <stack>

using namespace std;

/*
 题目描述：
    二叉树的非递归前序、中序、后序遍历
*/


// 二叉树的定义如下:
class Tree {
public:
    int value;
    Tree* left;
    Tree* right;
};

class Solution {
    void preOrder(Tree* root) {
        if (!root) {
            return;
        }
        stack<Tree*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Tree* node = stk.top();
            stk.pop();
            cout << node->value << endl;
            // 首先压入右节点使得左节点会先出栈
            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }
    }
    
    void inOrder(Tree* root) {
        if (!root) {
            return;
        }
        stack<Tree*> stk;
        while (!stk.empty() || root) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                cout << root->value << endl;
                root = root->left;
            }
        }
    }
    
    void postOrder(Tree* root) {
        if (!root) {
            return;
        }
        stack<Tree*> stk1;
        stack<Tree*> stk2;
        stk1.push(root);
        while (!stk1.empty()) {
            root = stk1.top();
            stk1.pop();
            stk2.push(root);
            
            if (root->left) {
                stk1.push(root->left);
                root = root->left;
            }
            
            if (root->right) {
                stk1.push(root->right);
                root = root->right;
            }
            
        }
        
        while (!stk2.empty()) {
            cout << stk2.top()->value <<endl;
            stk2.pop();
        }
    }
};

