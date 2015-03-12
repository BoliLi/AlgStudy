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
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p, *q;
        int i;
        p = head;
        for(i = 0; i < n; i++)
            p = p->next;
        q = head;
        while(p != NULL) {
            q = q->next;
            p = p->next;
        }
        ListNode *tmp = q->next;
        q->next = tmp->next;
        free(tmp);
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
    node = head;
    while(node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
    node = a.removeNthFromEnd(head, 4);
    while(node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
    cout << "Hello world!" << endl;
    return 0;
}
