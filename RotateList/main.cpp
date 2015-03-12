#include <iostream>
/*Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.*/
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *a, *b, *temp;
        a = head;
        for(int i = 0; i < k; i++) {
            if(a->next == NULL)
                return NULL;
            a = a->next;
        }

        b = head;

        while(a->next != NULL) {
            b = b->next;
            a = a->next;
        }

        a->next = head;
        temp = b->next;
        b->next = NULL;

        return temp;
    }
};

int main()
{
    Solution a;
    ListNode *node1 = new ListNode(1);
    ListNode *head = node1;
    ListNode *node2 = new ListNode(2);
    node1->next = node2;
    node1 = node2;
    node2 = new ListNode(3);
    node1->next = node2;
    node1 = node2;
    node2 = new ListNode(4);
    node1->next = node2;
    node1 = node2;
    node2 = new ListNode(5);
    node1->next = node2;
    node1 = node2;
    node2 = new ListNode(6);
    node1->next = node2;
    node1 = node2;

    node1 = head;
    while(node1 != NULL){
        cout << node1->val << " ";
        node1 = node1->next;
    }
    cout << endl;
    ListNode *ret = a.rotateRight(head, 2);
    while(ret != NULL){
        cout << ret->val << " ";
        ret = ret->next;
    }
    return 0;
}
