#include <iostream>

using namespace std;

/*
 题目描述：
    删除链表中的倒数第 K 个节点
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
    LinkedList* delete_node(LinkedList* head, int k) {
        if (!head || k < 1) {
            return head;
        }
        LinkedList* cur = head;
        while (cur) {
            k--;
            cur = cur->next;
        }
        
        if (k == 0) {
            head = head->next;
        }
        
        if (k < 0) {
            cur = head;
            while (++k != 0) {
                cur = cur->next;
            }
            cur->next = cur->next->next;
        }
        
        return head;
    }
};
