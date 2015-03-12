#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
/*Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3] */
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ret;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(ret, path, candidates, target, 0);
        return ret;
    }
private:
    void dfs(vector<vector<int> > &ret, vector<int> &path, vector<int> candidates, int target, int sum) {
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
            for(int i = 0; i < candidates.size(); i++) {
                if(path.size() != 0 && candidates[i] < path.back())
                    continue;
                path.push_back(candidates[i]);
                dfs(ret, path, candidates, target, sum + candidates[i]);
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
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(6);
    numbers.push_back(7);
    numbers.push_back(1);
    numbers.push_back(4);
    rt = a.combinationSum(numbers, 7);
    cout << "Hello world!" << endl;
    return 0;
}
