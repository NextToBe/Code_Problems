#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 题目描述：
    根据二叉树的先序遍历序列和中序遍历序列，生成后序遍历序列
 
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
    vector<int> getPostSeq(vector<int>& pre, vector<int>& in) {
        if (pre.empty() || in.empty() || pre.size() != in.size()) {
            return vector<int>();
        }
        int size = pre.size();
        vector<int> post(size);
        unordered_map<int, int> map;
        for (int i = 0; i < size; i++) {
            map[in[i]] = i;
        }
        
        setPost(pre, 0, size - 1, in, 0, size - 1, post, size - 1, map);
        return post;
    }
    
    int setPost(vector<int>& pre, int pre_start, int pre_end, vector<int>& in, int in_start, int in_end, vector<int>& post, int post_index, unordered_map<int, int>& map) {
        if (pre_start > pre_end) {
            return post_index;
        }
        
        post[post_index--] = pre[pre_start];
        int in_index = map[pre[pre_start]];
        
        post_index = setPost(pre, pre_end - in_end + in_index + 1, pre_end, in, in_index + 1, in_end, post, post_index, map);
        return setPost(pre, pre_start + 1, pre_start + 1 - in_start, in, in_start, in_index - 1, post, post_index, map);
    }
};
