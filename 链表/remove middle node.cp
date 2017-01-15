#include <iostream>

using namespace std;

/*
 题目描述：
    删除链表中的中间节点
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
    LinkedList* removeMiddleNode(LinkedList* head) {
        if (!head || !head->next) {
            return head;
        }
        
        LinkedList* fast = head;
        LinkedList* slow = head;
        
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};
