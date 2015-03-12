#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int> &num) {
        vector< vector<int> > ret;
        int i, j, k;
        int a, b, c;
        int sum;
        const int target = 13;

        ret.clear();
        sort(num.begin(), num.end());
        printf("<%s-%d>~%d~%d~%d~~~~\n", __FUNCTION__, __LINE__, num[0], num[1], num[2]);
        for(i = 0; i < num.size() - 2; i++) {
            if(num[i] == num[i + 1])
                continue;
            a = num[i];
            j = i + 1;
            k = num.size() - 1;
            while(j < k) {
                b = num[j];
                c = num[k];
                sum = a + b + c;
                if(sum < target) {
                    j++;
                } else if(sum > target) {
                    k--;
                } else {
                    j++;
                    k--;
                    printf("<%s-%d>~%d~%d~%d~~~~\n", __FUNCTION__, __LINE__, a, b, c);
                    vector<int> tmp;
                    tmp.push_back(a);
                    tmp.push_back(b);
                    tmp.push_back(c);
                    ret.push_back(tmp);
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution a;
    vector< vector<int> > ret;
    vector<int> numbers;
    vector<int> tmp;
    numbers.push_back(-1);
    numbers.push_back(-2);
    numbers.push_back(5);
    numbers.push_back(-3);
    numbers.push_back(-1);
    numbers.push_back(-7);
    numbers.push_back(0);
    numbers.push_back(7);
    numbers.push_back(1);
    ret = a.threeSum(numbers);
    tmp = ret[0];
    cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;
    return 0;
}
