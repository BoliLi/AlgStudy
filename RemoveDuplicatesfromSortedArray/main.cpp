#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int pos = 0;
        int max = 0;

        for(int i = 0; i < n; i++) {
            if(A[i] > max) {
                A[pos++] = A[i];
                max = A[i];
            }
        }
        return pos;
    }
};

int main()
{
    Solution a;
    int ret;
    int A[10] = {1, 1, 2, 3, 3, 3, 4, 5, 6, 7};
    ret = a.removeDuplicates(A, 10);
    cout << ret << endl;
    return 0;
}
