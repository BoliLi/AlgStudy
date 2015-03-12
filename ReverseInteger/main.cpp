#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int r = 0;

        while(x) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }
};

int main()
{
    Solution a;

    cout << a.reverse(-123) << endl;
    return 0;
}
