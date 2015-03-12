#include <iostream>
/*You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int *s = new int[n];
        s[0] = 1;
        s[1] = 2;

        for(int i = 2; i < n; i++) {
            s[i] = s[i - 1] + s[i - 2];
        }
        delete[] s;
        return s[n - 1];
    }
};

int main()
{
    Solution a;
    cout << a.climbStairs(4) << endl;
    return 0;
}
