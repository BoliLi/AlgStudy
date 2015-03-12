#include <iostream>
#include <stdio.h>
/*Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would
be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0*/

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;

        while(left < right) {
            int mid = left + (right - left) / 2;
            if(A[mid] < target) {
                left = mid + 1;
            } else if(A[mid] > target) {
                right = mid - 1;
            } else {
                printf("[%s-%d]~%d~~~~~~\n", __FUNCTION__, __LINE__, mid);
                return mid;
            }
        }
        printf("[%s-%d]~%d~%d~~~~~\n", __FUNCTION__, __LINE__, left, right);
        if(A[left] < target)
            return left + 1;
        else if(A[left] > target)
            return left - 1;
        else
            return left;
    }
};

int main()
{
    Solution a;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    a.searchInsert(arr, 7, 3);
    cout << "Hello world!" << endl;
    return 0;
}
