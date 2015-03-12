#include <iostream>
#include <algorithm>
/*Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach,
which is more subtle.*/
using namespace std;
//贪心算法如果+A[i]比A[i]还小的话则将A[i]作为subarray的开头
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ret = 0;
        int mid = A[0];
        for(int i = 1; i < n; i++) {
            mid = max(mid + A[i], A[i]);
            ret = max(ret, mid);
        }
        return ret;
    }
};

int main()
{
    Solution a;
    int arr[] = {-2, 1, -3, 4, -1, -1, -1, -1, -5, -7};

    cout << a.maxSubArray(arr, 10) << endl;
    return 0;
}
