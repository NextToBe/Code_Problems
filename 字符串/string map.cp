#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 题目描述：
    判断两个字符串是否互为变型串
 
*/


class Solution {
public:
    bool isDeformartion(string s, string k) {
        if (s.length() != k.length()) {
            return false;
        }
        vector<char> map(256, 0);
        for (auto ch : s) {
            map[ch]++;
        }
        
        for (auto ch : k) {
            if (map[ch]-- == 0) {
                return false;
            }
        }
        
        return true;
    }

};
