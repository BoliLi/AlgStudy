#include <iostream>
#include <vector>
#include <map>
/*Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2*/
using namespace std;
//hash
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> map1;
        vector<int> rt;
        map<int, int>::iterator iter;
        for(int i = 0; i < numbers.size(); i++) {
            map1.insert(pair<int, int>(numbers[i], i));
        }
        for(int i = 0; i < numbers.size(); i++) {
            int gap = target - numbers[i];
            if(gap * 2 != target) {
                iter = map1.find(gap);
                if(iter != map1.end() && map1[gap] > i) {
                    rt.push_back(i + 1);
                    rt.push_back(map1[gap] + 1);
                    return rt;
                }
            } else {
                rt.push_back(i + 1);
                for(int j = i + 1; j < numbers.size(); j++) {
                    if(numbers[j] == gap) {
                        rt.push_back(j + 1);
                        return rt;
                    }
                }
                rt.pop_back();
            }
        }
        return rt;
    }
};

int main()
{
    Solution a;
    vector<int> rt;
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(7);
    numbers.push_back(15);
    rt = a.twoSum(numbers, 17);
    cout << rt[0] << " " << rt[1] << endl;
    return 0;
}
