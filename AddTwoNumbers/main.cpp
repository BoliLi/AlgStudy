#include <iostream>
/*You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8*/
using namespace std;
//Use l1 as the result. If l1 is shorter than l2, then connect l1 tail with the reset of l2
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        int carry = 0;

        while(node1 != NULL || node2 != NULL) {
            int val1 = (node1 == NULL ? 0 : node1->val);
            int val2 = (node2 == NULL ? 0 : node2->val);

            val1 += val2;
            if(carry)
                val1 += 1;
            if(val1 >= 10)
                carry = 1;
            else
                carry = 0;
            val1 %= 10;
            cur->next = new ListNode(val1);
            cur = cur->next;
            if(node1 != NULL)
                node1 = node1->next;
            if(node2 != NULL)
                node2 = node2->next;
        }

        if(carry)
            cur->next = new ListNode(1);
        return dummy.next;
    }
};

int main()
{
    Solution a;
    ListNode *node1 = new ListNode(1);
    ListNode *head1 = node1;
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

    node1 = head1;
    while(node1 != NULL){
        cout << node1->val << " ";
        node1 = node1->next;
    }
    cout << endl;

    node1 = new ListNode(1);
    node2 = new ListNode(3);
    ListNode *head2 = node1;
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
    node2 = new ListNode(6);
    node1->next = node2;
    node1 = node2;
    node2 = new ListNode(9);
    node1->next = node2;
    node1 = node2;
    node2 = new ListNode(9);
    node1->next = node2;
    node1 = node2;

    node1 = head2;
    while(node1 != NULL){
        cout << node1->val << " ";
        node1 = node1->next;
    }
    cout << endl;

    node1 = a.addTwoNumbers(head1, head2);
    while(node1 != NULL){
        cout << node1->val << " ";
        node1 = node1->next;
    }
    cout << endl;
    return 0;
}
