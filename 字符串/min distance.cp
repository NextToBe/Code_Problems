#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 题目描述：
    给定一个字符串数组 strs, 再给定两个字符串 str1 和 str2, 返回在 strs 中 str1 与 str2 的最小距离
*/


class Solution {
public:
    int minDistance(vector<string>& strs, string str1, string str2) {
        if (str1.empty() || str2.empty()) {
            return -1;
        }
        
        if (str2 == str1) {
            return 0;
        }
        
        int last1 = -1, last2 = -1;
        int res = INT_MAX;
        
        for (auto i = 0; i < strs.size(); i++) {
            if (strs[i] == str1) {
                last1 = i;
                res = min(res, last2 == -1 ? res : i - last2);
            }
            
            if (strs[i] == str2) {
                last2 = i;
                res = min(res, last1 == -1 ? res : i - last1);
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};
