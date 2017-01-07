#include <iostream>
#include<stack>
using namespace std;

/*
 题目描述：
    使用递归函数和栈操作逆序一个栈
*/

void init(stack<int>&);
int get_and_remove_last_element(stack<int>&);
void reverse(stack<int>&);

int main() {
    // test
    stack<int> stk;
    init(stk);
    reverse(stk);
    while (!stk.empty()) {
        cout << stk.top() <<endl;
        stk.pop();
    }
    return 0;
}

void init(stack<int>& stk) {
    stk.push(1),stk.push(2),stk.push(3);
}

int get_and_remove_last_element(stack<int>& stk) {
    int res = stk.top();
    stk.pop();
    
    if (stk.empty()) {
        return res;
    } else {
        int last = get_and_remove_last_element(stk);
        stk.push(res);
        return last;
    }
}

void reverse(stack<int>& stk) {
    if (stk.empty()) {
        return;
    }
    int element = get_and_remove_last_element(stk);
    //cout<<element<<endl;
    reverse(stk);
    stk.push(element);
}
