#include <iostream>
#include <vector>
#include <map>

using namespace std;

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
