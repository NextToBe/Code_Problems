#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

/*
 题目描述：
    给定一个字符串，返回字符串 str 中最长的无重复的子串的长度。
*/

/*----------------------------------------------------------------------------------*/

class Solution {
public:
    int longestUniqueSubstr(string s) {
        if (s.empty()) {
            return 0;
        }
        
        vector<int> map(256, -1);
        int len= 0, cur = 0, pre = -1;
        for (int i = 0; i < s.size(); i++) {
            pre = max(pre, map[s[i]]);
            cur = i - pre;
            len = max(cur, len);
            map[s[i]] = i;
        }
        
        return len;
    }

};


