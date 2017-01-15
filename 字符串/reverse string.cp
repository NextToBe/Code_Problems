#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 题目描述：
    给定一个字符串和一个整数 size, 请把大小为 size 的左半区整体移到右半区
    时间复杂度O(n), 空间复杂度O(1)
*/


class Solution {
public:
    string rotate(string s, int size) {
        if (s.empty() || size <= 0) {
            return s;
        }
        
        reverse(s, 0, size - 1);
        reverse(s, size, s.size() - 1);
        reverse(s, 0, s.size() - 1);
        
        return s;
    }
    
    string reverse(string& s, int start, int end) {
        if (s.empty() || start < 0 || end >= s.size() || end < start) {
            return s;
        }
        
        while (start < end) {
            swap(s[start++], s[end--]);
        }
        
        return s;
    }
};
