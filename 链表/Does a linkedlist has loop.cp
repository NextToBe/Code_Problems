#include <iostream>
#include <stack>

using namespace std;

/*
 题目描述：
    判断一个链表是否有环，有则返回环的入口，否则返回 null
*/


// 链表的定义如下:
class LinkedList {
public:
    int value;
    LinkedList* next;
};

/*----------------------------------------------------------------------------------*/


class Solution {
    LinkedList* hasLoop(LinkedList* head) {
        if (!head || !head->next) {
            return nullptr;
        }
        LinkedList* fast = head, *slow = head;
        while (slow != fast) {
            if (!slow->next || !fast->next->next) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast;
    }
};
