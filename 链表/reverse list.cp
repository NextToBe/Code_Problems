#include <iostream>

using namespace std;

/*
 题目描述：
    翻转链表
*/

// 链表的定义如下:
class LinkedList {
public:
    int value;
    LinkedList* next;
};

/*----------------------------------------------------------------------------------*/

class Solution {
public:
    LinkedList* reverseList(LinkedList* head) {
        if (!head || !head->next) {
            return head;
        }
        LinkedList* pre = nullptr;
        LinkedList* next = nullptr;
        
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        
        return pre;
    }
};
