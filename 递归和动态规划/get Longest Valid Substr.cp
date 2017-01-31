#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>


using namespace std;

/*
 题目描述：
    给定一个字符串 str，返回最长的有效括号子串长度：(())()，返回6， ))()())), 返回4
*/

/*----------------------------------------------------------------------------------*/

class Solution {
public:
    int getLongestValidSubstr(string s) {
        int size = s.size();
        if (size == 0) {
            return 0;
        }
        vector<int> dp(size, 0); // dp[i] = 以 str[i]结尾的最长有效子串长度
        int pre = 0, res = 0;
        for (int i = 1; i < size; i++) {
            if (s[i] == ')') {
                pre = i - dp[i - 1] - 1;
                if (pre >= 0 && s[pre] == '(') {
                    dp[i] = dp[i - 1] + 2 + pre > 0 ? dp[pre -1] : 0;
                }
            }
            
            res = max(res, dp[i]);
        }
        
        return res;
    }
    

};


