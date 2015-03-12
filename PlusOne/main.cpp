#include <iostream>
#include <vector>
/*Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.*/
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int i;
        for(i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] + 1 > 9)
                digits[i] = 0;
            else {
                digits[i] += 1;
                break;
            }
        }

        if(i == -1 && digits[0] == 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    Solution a;
    vector<int> digits(3, 2);

    a.plusOne(digits);
    for(int i : digits)
        cout << i;
    return 0;
}
