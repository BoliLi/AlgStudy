#include <iostream>
/*Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].*/
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int pos = 0;
        int max = 0;
        int dupCnt = 0;

        for(int i = 0; i < n; i++) {
            if(A[i] > max) {
                A[pos++] = A[i];
                max = A[i];
                dupCnt = 0;
            } else {
                dupCnt++;
                if(dupCnt < 2)
                    A[pos++] = A[i];
            }
        }

        return pos;
    }
};

int main()
{
    Solution a;
    int A[10] = {1, 1, 1, 3, 3, 3, 4, 5, 6, 7};
    cout << a.removeDuplicates(A, 10) << endl;
    return 0;
}
