#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int pos1, pos2;
        int i, j;
        for(i = num.size() - 2; i >= 0; i--) {
            if(num[i] < num[i + 1])
                break;
        }

        if(i < 0) {
            reverse(num.begin(), num.end() - 1);
            return;
        }

        for(j = num.size() - 1; j >= 0; j--) {
            if(num[j] > num[i])
                break;
        }

        swap(num[j], num[i]);
        reverse(num.begin() + i + 1, num.end() - 1);
    }
private:
    void reverse(vector<int>::iterator i1, vector<int>::iterator i2) {
        while (i1 < i2) {
            *i1 ^= *i2;
            *i2 ^= *i1;
            *i1 ^= *i2;

            i1++;
            i2--;
        }
    }
};

int main()
{
    Solution a;
    vector<int> num;
    num.push_back(6);
    num.push_back(3);
    num.push_back(7);
    num.push_back(8);
    a.nextPermutation(num);
    printf("%d %d %d %d\n", num[0], num[1], num[2], num[3]);
    cout << "Hello world!" << endl;
    return 0;
}
