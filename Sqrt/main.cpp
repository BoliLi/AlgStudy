#include <iostream>
/*Implement int sqrt(int x).

Compute and return the square root of x.*/
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        int left = 1, right = x / 2;
        int last_mid;

        while(left <= right) {
            int mid = (right - left) / 2 + left;
            if(x / mid < mid) {
                right = mid - 1;
            } else if(x / mid > mid) {
                left = mid + 1;
                last_mid = mid;
            } else {
                return mid;
            }
        }
        return last_mid;
    }
};

int main()
{
    Solution a;
    cout << a.sqrt(7) << endl;
    return 0;
}
