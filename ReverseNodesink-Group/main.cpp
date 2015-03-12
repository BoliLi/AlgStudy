#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *reverseList(ListNode *head, ListNode *nextHead) {
        ListNode *pre, *cur, *next;
        cur = head->next;
        pre = head;
        pre->next = nextHead;
        while(cur != NULL) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *start, *end;
        ListNode *pre, *next;
        ListNode *node;
        ListNode dummy(-1);

        end = head;
        for(int i = 0; i < k - 1; i++) {
            if(end == NULL)
                return head;
            end = end->next;
        }
        start = head;

        next = end->next;
        end->next = NULL;
        end = start;
        start = reverseList(start, next);
        head = start;
        pre = &dummy;
        pre->next = head;

        int cnt = 0;
        while(end != 0) {
            pre = pre->next;
            start = start->next;
            end = end->next;
            if(++cnt == k) {
                cnt = 0;
                next = end->next;
                end->next = NULL;
                end = start;
                start = reverseList(start, next);
                pre->next = start;
            }
        }
        return head;
    }
};

int main()
{
    ListNode *node;
    ListNode *head;
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
    node = a.reverseKGroup(head, 4);
    while(node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
    cout << "Hello world!" << endl;
    return 0;
}
