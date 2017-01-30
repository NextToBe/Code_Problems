#include <iostream>
#include <vector>

using namespace std;

/*
 题目描述：
 给定数组 arr，arr 中所有的值都是正整数且不重复，每个值都代表一个面值，每种面值的货币可以使用任意张，再给定一个整数 aim 代表要找的钱数，求换钱的方法数
 
 */



/*----------------------------------------------------------------------------------*/


class Solution {
public:
    int getMethodNum(vector<int>& arr, int aim) {
        if (arr.empty() || aim == 0) {
            return 0;
        }
        
        vector<int> dp(aim + 1, 0);
        for (int num = 0; arr[0] * num <= aim; num++) {
            dp[arr[0] * num] = 1;
        }
        
        for (int i = 1; i < arr.size(); i++) {
            for (int money = 0; money <= aim; money++) {
                dp[money] += money - arr[i] > 0 ? dp[money - arr[i]] : 0;
            }
        }
        
        return dp[aim];
    }
    
};

