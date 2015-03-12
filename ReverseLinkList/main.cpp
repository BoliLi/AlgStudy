#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre, *cur, *next;
        cur = head->next;
        pre = head;
        pre->next = NULL;
        while(cur != NULL) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

int main()
{
    int i;
    ListNode *head;
    ListNode *node;
    Solution a;

    head = (ListNode *)malloc(sizeof(ListNode));
    head->val = 0;
    head->next = NULL;
    node = head;
    for(int i = 1; i < 10; i++) {
        ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
        tmp->val = i;
        tmp->next = NULL;
        node->next = tmp;
        node = node->next;
    }

    node = a.reverseList(head);
    while(node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    cout << "Hello world!" << endl;
    return 0;
}
