#include <iostream>
#include <string>
#include <algorithm>
/*Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".*/
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int len = max(a.size(), b.size());
        string ret = "";
        int carry = 0;
        int i, j, k;

        for(i = len, j = a.size() - 1, k = b.size() - 1; i > 0; i--, j--, k--) {
            if(j < 0) {
                if(b[k] == '1') {
                    if(carry) {
                        ret = "0" + ret;
                        carry = 1;
                    } else {
                        ret = "1" + ret;
                        carry = 0;
                    }
                } else {
                    if(carry) {
                        ret = "1" + ret;
                        carry = 0;
                    } else {
                        ret = "0" + ret;
                        carry = 0;
                    }
                }
                continue;
            }

            if(k < 0) {
                if(a[j] == '1') {
                    if(carry) {
                        ret = "0" + ret;
                        carry = 1;
                    } else {
                        ret = "1" + ret;
                        carry = 0;
                    }
                } else {
                    if(carry) {
                        ret = "1" + ret;
                        carry = 0;
                    } else {
                        ret = "0" + ret;
                        carry = 0;
                    }
                }
                continue;
            }

            if(a[j] == '1' && b[k] == '1') {
                if(carry) {
                    ret = "1" + ret;
                } else {
                    ret = "0" + ret;
                    carry = 1;
                }
            } else if(a[j] == '0' && b[k] == '0') {
                if(carry) {
                    ret = "1" + ret;
                    carry = 0;
                } else {
                    ret = "0" + ret;
                    carry = 0;
                }
            } else {
                if(carry) {
                    ret = "0" + ret;
                    carry = 1;
                } else {
                    ret = "1" + ret;
                    carry = 0;
                }
            }
        }

        if(carry)
            ret = "1" + ret;

        return ret;
    }
};

int main()
{
    Solution a;

    cout << a.addBinary("1100", "101") << endl;
    return 0;
}
