#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
/*Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]*/
using namespace std;

class Solution {

public:
    int cnt = 0;
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ret;
        vector<int> path;
        sort(num.begin(), num.end());
        dfs(ret, path, num, target, 0, 0);
        return ret;
    }
private:
    void dfs(vector<vector<int> > &ret, vector<int> &path, vector<int> &num, int target, int curPos, int sum) {

        if(sum == target) {
            ret.push_back(path);
            for(int i = 0; i < path.size(); i++) {
                printf("%d ", path[i]);
            }
            printf("\n");
            return;
        } else if(sum > target) {
            return;
        } else {
            for(int i = curPos; i < num.size(); i++) {
                if(path.size() != 0 && num[i] < path.back())
                    continue;
                path.push_back(num[i]);
                //printf("[%s-%d]~%d~%d~%d~%d~%d~~\n", __FUNCTION__, __LINE__, num[i], i, curPos, sum, cnt++);
                dfs(ret, path, num, target, i + 1, sum + num[i]);
                cnt--;
                path.pop_back();
            }
        }
    }
};

int main()
{
    Solution a;
    vector<vector<int> > rt;
    vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(6);
    numbers.push_back(1);
    numbers.push_back(5);
    a.combinationSum2(numbers, 8);
    cout << "Hello world!" << a.cnt <<endl;
    return 0;
}
