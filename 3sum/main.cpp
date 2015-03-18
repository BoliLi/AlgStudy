#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
/*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)*/
using namespace std;
/*先将源数据排序，然后左右夹逼*/
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
