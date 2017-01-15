#include <iostream>

using namespace std;

/*
 题目描述：
    打印两个有序链表的公共部分
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
    void printCommonParts(LinkedList* head1, LinkedList* head2) {
        while (head1 && head2) {
            if (head1->value < head2->value) {
                head1 = head1->next;
            } else if (head1->value > head2->value) {
                head2 = head2->next;
            } else {
                cout << head1->value << endl;
                head1 = head1->next;
                head2 = head2->next;
            }
        }
    }
};
