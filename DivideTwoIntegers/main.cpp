#include <iostream>
#include <algorithm>
/*Divide two integers without using multiplication, division and mod operator.*/
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ? -1 : 1;
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
        return sign * ret;
    }
};

int main()
{
    Solution a;
    cout << a.divide(128, 7) << endl;
    return 0;
}
