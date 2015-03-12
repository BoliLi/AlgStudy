#include <iostream>
/* The set [1,2,3,бн,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.*/
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int *factorial = new int[n]();
        bool *seleted = new bool[n + 1]();

        string ret = "";
        factorial[0] = 1;
        factorial[1] = 1;

        for(int i = 2; i < n; i++)
            factorial[i] = factorial[i - 1] * i;
        int remainK = k - 1;
        for(int i = n; i > 0; i--) {
            for(int j = 1; j <= n; j++) {
                if(seleted[j])
                    continue;
                if(remainK >= factorial[i - 1]) {
                    remainK -= factorial[i - 1];
                    continue;
                }

                if(remainK < factorial[i - 1] || remainK == 0) {
                    ret += ('0' + j);
                    seleted[j] = true;
                    break;
                }
            }
        }
        cout << ret << endl;
        return ret;
    }
};

int main()
{
    Solution a;
    a.getPermutation(3, 5);
    cout << "Hello world!" << endl;
    return 0;
}
