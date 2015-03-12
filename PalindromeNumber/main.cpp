#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int tmp = x;
        int i = 0;
        bool ret = true;

        i = 1;
        while(tmp) {
            i *= 10;;
            tmp /= 10;
        }

        i /= 10;
        while(x) {
            int a = x / i;
            int b = x % 10;
            if(a != b)
                return false;
            x %= i;
            x /= 10;
            i /= 100;
        }
        return true;
    }
};

int main()
{
    Solution a;

    cout << a.isPalindrome(1211) << endl;
    return 0;
}
