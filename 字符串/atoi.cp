#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 题目描述：
    字符串转 int(atoi)
 
*/


class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, base = 0, i = 0;
        while (str[i] == ' ') {
            i++;
        }
        if (str[i] == '-' || str[i] == '+') {
            sign = 1 - 2 * (str[i++] == '-');
        }
        
        while (isdigit(str[i])) {
            // INT_MAX = 2147483648
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            base = 10 * base + str[i++] - '0';
        }
        
        return base * sign;
    }
    
};
