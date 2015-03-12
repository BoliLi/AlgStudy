#include <iostream>
#include <vector>
#include <stdio.h>
/*Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].*/
using namespace std;

//使用二分查找获取目标在数组中的上界和下界
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        int l, r;

        l = lSearch(A, n, target);
        r = rSearch(A, n, target);
        printf("[%s-%d]~%d~%d~~~~~\n", __FUNCTION__, __LINE__, l, r);
        return ret;
    }
private:
    int lSearch(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;

        while(left < right) {
            int mid = left + (right - left) / 2;
            if(A[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        if(A[left] != target) {
            return -1;
        } else {
            return left;
        }
    }

    int rSearch(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;

        while(left < right) {
            int mid = left + (right - left) / 2 + 1; // 注意+1
            if(A[mid] > target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }

        if(A[right] != target) {
            return -1;
        } else {
            return right;
        }
    }
};

int main()
{
    Solution a;
    int arr[] = {1, 2, 3, 4, 4, 4, 5};
    a.searchRange(arr, 7, 7);
    cout << "Hello world!" << endl;
    return 0;
}
