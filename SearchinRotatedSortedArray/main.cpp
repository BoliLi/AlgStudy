#include <iostream>
/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.*/
using namespace std;
//二分查找，加一些边界判断
class Solution {
public:
    int search(int A[], int n, int target) {
        return dfs(A, 0, n - 1, target);
    }
private:
    int dfs(int A[], int start, int end, int target) {
        int mid = start + (end - start) / 2;
        if(A[start] == target)
            return start;
        if(start == end)
            return -1;
        if(A[start] < A[end] && (A[start] <= target && A[end] >= target)) {
            if(A[mid] > target)
                return dfs(A, start, mid, target);
            else
                return dfs(A, mid + 1, end, target);
        } else {
            if(A[start] < A[mid] && (A[start] <= target && A[mid] >= target))
                return dfs(A, start, mid, target);
            else if(A[mid + 1] < A[end] && (A[mid + 1] <= target && A[end] >= target))
                return dfs(A, mid + 1, end, target);
            else if(A[start] > A[mid] && (A[start] <= target || A[mid] >= target))
                return dfs(A, start, mid, target);
            else if(A[mid + 1] > A[end] && (A[mid + 1] <= target || A[end] >= target))
                return dfs(A, mid + 1, end, target);
            else
                return -1;
        }
    }
};

int main()
{
    Solution a;
    int arr[] = {9, 12, 13, 2, 3, 4};
    cout << a.search(arr, 6, 9) << endl;
    return 0;
}
