#include <iostream>
#include <string>
#include <stdio.h>
/*Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.*/
using namespace std;
//num1的第i位与num2的第j位相乘结果存在i+j+1位置，+1是为了进位
class Solution {
public:
    string multiply(string num1, string num2) {
        int *result = new int[num1.length() + num2.length()]();
        int i, j;
        string ret;

        for(i = 0; i < num1.length(); i++) {
            for(j = 0; j < num2.length(); j++) {
                result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        for(i = num1.length() + num2.length() - 1; i > 0; i--) {
            result[i - 1] += result[i] / 10;
            result[i] %= 10;
        }

        i = 0;
        if(result[0] == 0)
            i++;
        j = 0;
        while(i < num1.length() + num2.length()) {
            ret = ret + char(result[i++] + '0');
        }

        return ret;
    }
};

int main()
{
    Solution a;
    cout << a.multiply("543", "678") << endl;
    return 0;
}
