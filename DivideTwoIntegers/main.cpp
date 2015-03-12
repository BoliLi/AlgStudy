#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int a = abs(dividend);
        int b = abs(divisor);
        int i, ret = 0;

        while(a >= b) {
            int c = b;
            i = 0;
            while(a >= c) {
                a -= c;
                ret += 1 << i;
                i++;
                c <<= 1;
            }
        }
        return ret;
    }
};

int main()
{
    Solution a;
    cout << a.divide(128, 7) << endl;
    return 0;
}
