#include <iostream>
#include <algorithm>
#include <stdio.h>
/*Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.*/
using namespace std;
//思想就是将i（0<i<n）放到A[i - 1]
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        bucket_sort(A, n);
        for (int i = 0; i < n; ++i)
            if (A[i] != (i + 1))
                return i + 1;
        return n + 1;
    }
private:
    static void bucket_sort(int A[], int n) {
        for (int i = 0; i < n; i++) {
            while (A[i] != i + 1) {
                //If A[i] is not in the range (0, n], then no swap
                if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
                    break;
                swap(A[i], A[A[i] - 1]);
            }
            for(int j = 0; j < n; j++) {
                printf("%d ", A[j]);
            }
            printf("\n");
        }
    }
};

int main()
{
    Solution a;
    int arr[] = {3, -4, 1, 5, 0};

    cout << a.firstMissingPositive(arr, 5) << endl;
    return 0;
}
