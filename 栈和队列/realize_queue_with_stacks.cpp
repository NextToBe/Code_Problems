#include <iostream>
#include<stack>
using namespace std;

/*
 题目描述：
    使用两个栈实现队列, 支持队列的基本操作: add, poll, peek
 
*/


class Queue {
private:
    stack<int> push_stk;
    stack<int> pop_stk;
    
public:
    void add(int num) {
        this->push_stk.push(num);
    }
    
    int poll() {
        if (this->push_stk.empty() && this->pop_stk.empty()) {
            return -1;
        } else if (this->pop_stk.empty()) {
            while (!this->push_stk.empty()) {
                this->pop_stk.push(this->push_stk.top());
                this->push_stk.pop();
            }
        }
        int ret = this->pop_stk.top();
        this->pop_stk.pop();
        return ret;
    }
    
    int peek() {
        if (this->push_stk.empty() && this->pop_stk.empty()) {
            return -1;
        } else if (this->pop_stk.empty()) {
            while (!this->push_stk.empty()) {
                this->pop_stk.push(this->push_stk.top());
                this->push_stk.pop();
            }
        }
        
        return this->pop_stk.top();
    }
};
