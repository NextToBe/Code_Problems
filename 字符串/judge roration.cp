#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 题目描述：
    判断两个字符串是否互为旋转串
 
*/


class Solution {
public:
    bool isRotation(string s, string k) {
        if (s.length() != k.length()) {
            return false;
        }
        string str = k + k;
        
        if (str.find(s) == string::npos) {
            return false;
        } else {
            return true;
        }
    }

};
