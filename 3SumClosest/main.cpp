#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
/*Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/
using namespace std;
/*ÏÈÅÅĞò£¬È»ºó×óÓÒ¼Ğ±Æ*/
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int diff = 0x7FFFFFFF;
        int sum = 0;
        int ret = 0;
        int i, j, k;
        int a, b, c;
        sort(num.begin(), num.end());
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
                if(diff > abs(sum - target)) {
                    diff = abs(sum - target);
                    ret = sum;
                }
                if(sum < target) {
                    j++;
                } else if(sum > target) {
                    k--;
                } else {
                    printf("<%s-%d>~%d~%d~%d~~~~\n", __FUNCTION__, __LINE__, a, b, c);
                    return sum;
                }
            }
        }

        return ret;
    }
};

int main()
{
    Solution a;
    vector<int> numbers;

    numbers.push_back(-1);
    numbers.push_back(-2);
    numbers.push_back(5);
    numbers.push_back(-3);
    numbers.push_back(-1);
    numbers.push_back(-7);
    numbers.push_back(0);
    numbers.push_back(7);
    numbers.push_back(1);
    cout << a.threeSumClosest(numbers, 12) << endl;
    return 0;
}
