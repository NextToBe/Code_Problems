#include <iostream>
#include<stack>

using namespace std;

/*
 题目描述：
    用一个栈实现另一个栈的排序
*/

void sort_stack(stack<int>& stk) {
    stack<int> helper;
    while (!stk.empty()) {
        int cur = stk.top();
        stk.pop();
        
        while (!helper.empty() && helper.top() < cur) {
            stk.push(helper.top());
            helper.pop();
        }
        helper.push(cur);
    }
    
    while (!helper.empty()) {
        stk.push(helper.top());
        helper.pop();
    }
}



