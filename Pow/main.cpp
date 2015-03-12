#include <iostream>
/*Implement pow(x, n).*/
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if(n < 0)
            return pow(x, -n);
        if(n == 0)
            return 1.0;
        double mid = pow(x, n >> 1);
        if(n % 2)
            return mid * mid * x;
        else
            return mid * mid;
    }
};

int main()
{
    Solution a;
    cout << a.pow(2, 15) << endl;
    return 0;
}
