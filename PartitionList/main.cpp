#include <iostream>
/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.*/
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode left_dummy(-1);
        ListNode right_dummy(-1);
        ListNode *curLeft = &left_dummy;
        ListNode *curRight = &right_dummy;

        for(ListNode *cur = head; cur; cur = cur->next) {
            if(cur->val < x) {
                curLeft->next = cur;
                curLeft = cur;
            } else {
                curRight->next = cur;
                curRight = cur;
            }
        }

        curLeft->next = right_dummy.next;
        curRight->next = NULL;
        return left_dummy.next;
    }
};

int main()
{
    Solution a;
    ListNode node(1);
    ListNode *next;
    cout << "Hello world!" << endl;
    return 0;
}
