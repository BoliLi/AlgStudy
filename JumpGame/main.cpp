#include <iostream>
/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.*/
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        return dfs(A, n, 0);
    }
private:
    bool dfs(int A[], int n, int pos) {
        if(pos == n - 1)
            return true;
        for(int i = A[pos]; i > 0 ; i--) { //贪心，从最大步数起跳
            if(dfs(A, n, pos + i))
                return true;
        }
        return false;
    }
};

/*DP, f[i] represents maximum remain steps to reach A[i]*/
class Solution1 {
public:
    bool canJump(int A[], int n) {
        int f[n];
        f[0] = 0;
        for(int i = 1; i < n; i++) {
            f[i] = max(f[i-1], A[i-1]) - 1;
            if(f[i] < 0)
                return false;
        }
        cout << f[n-1] << endl;
        return f[n-1] >= 0;
    }
};

int main()
{
    Solution1 a;
    int arr[] = {3,2,1,1,4};
    cout << a.canJump(arr, 5) << endl;
    return 0;
}
