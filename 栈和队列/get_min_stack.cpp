#include <iostream>
#include<stack>
using namespace std;

/*
 题目描述：
    实现一个特殊的栈，在实现栈的基础上，实现返回栈的最小元素的操作
    pop, push, getMin 操作的时间复杂度都是O(1)
 
*/

class myStack {
private:
    stack<int> data;
    stack<int> min;
    
public:
    
    int getMin() {
        if (this->min.empty()) {
            return -1;
        } else {
            return this->min.top();
        }
    }
    
    void push(int num) {
        if (this->min.empty()) {
            this->min.push(num);
        } else if (num <= this->getMin()) {
            this->min.push(num);
        }
        
        data.push(num);
    }
    
    void pop() {
        if (this->data.empty()) {
            return;
        }
        int value = this->data.top();
        this->data.pop();
        if (value == this->min.top()) {
            this->min.pop();
        }
    }
};

