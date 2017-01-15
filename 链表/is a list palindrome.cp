#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 题目描述：
    判断一个链表是否是回文结构
*/


// 链表的定义如下:
class LinkedList {
public:
    int value;
    LinkedList* next;
};

class Solution {
    bool isPalindrome(LinkedList* head) {
        if (!head || !head->next) {
            return false;
        }
        LinkedList* fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        LinkedList* head2 = reverse(slow->next);
        slow->next = nullptr;
        
        while (head2) {
            if (head->value != head2->value) {
                return false;
            }
            head2 = head2->next;
            head = head->next;
        }
        
        return true;
    }
    
    LinkedList* reverse(LinkedList* head) {
        if (!head || !head->next) {
            return head;
        }
        LinkedList* pre = nullptr, *next = nullptr;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};

