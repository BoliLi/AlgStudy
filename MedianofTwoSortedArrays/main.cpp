#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int k = m + n;
        if(k & 1)
            return findMedian(A, m, B, n, (k / 2) + 1);
        else
            return (findMedian(A, m, B, n, k / 2) + findMedian(A, m, B, n, (k / 2) + 1)) / 2.0;
    }

private:
    int findMedian(int A[], int m, int B[], int n, int k) {
        if(m > n)
            return findMedian(B, n, A, m, k);
        if(k == 1)
            return min(A[0], B[0]);
        if(m == 0)
            return B[k - 1];

        int ia = min(k / 2, m), ib = k - ia;
        if(A[ia - 1] > B[ib - 1])
            return findMedian(A, m, B + ib, n - ib, k - ib);
        else if(A[ia - 1] < B[ib - 1])
            return findMedian(A + ia, m - ia, B, n, k - ia);
        else
            return min(A[ia - 1], B[ib - 1]);
    }
};

int main()
{
    int A[10] = {2, 3, 8, 9, 11, 13};
    int B[10] = {1, 3, 6, 7};
    Solution sol;
    cout << sol.findMedianSortedArrays(A, 6, B, 4) << endl;
    return 0;
}
