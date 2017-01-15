#include <iostream>

using namespace std;

/*
 题目描述：
    翻转部分链表
    1->2->3->4->5->null from = 2, to = 4:
        1->4->3->2->5->null
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
    LinkedList* reversePartList(LinkedList* head, int from, int to) {
        int length = 0;
        LinkedList* cur = head;
        LinkedList* left = nullptr, *right = nullptr;
        while (cur) {
            length++;
            left = length == from - 1 ? cur : left;
            right = length == to + 1 ? cur : right;
            cur = cur->next;
        }
        
        if (!head || from < to || from < 1 || to > length) {
            return head;
        }
        
        LinkedList* node1 = left == nullptr ? head : left->next;
        LinkedList* node2 = node1->next;
        
        node1->next = right;
        LinkedList* next = nullptr;
        while (node2 != right) {
            next = node2->next;
            node2->next = node1;
            node1 = node2;
            node2 = next;
        }
        
        if (left) {
            left->next = node1;
            return head;
        }
        return node1;
    }
    

};
