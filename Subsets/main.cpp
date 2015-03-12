#include <iostream>
#include <vector>
#include <algorithm>
/*Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
using namespace std;

class Solution {
    void dfs(vector<int> &S, vector<vector<int> > &ret, vector<int> &mid, int step, int n) {
        if(step == n) {
            ret.push_back(mid);
            for(int j = 0; j < mid.size(); j++)
                cout << mid[j] << " ";
            cout << endl;
            return;
        }

        mid.push_back(S[step]);
        dfs(S, ret, mid, step + 1, n);
        mid.pop_back();

        dfs(S, ret, mid, step + 1, n);
    }
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ret;
        vector<int> mid;
        sort(S.begin(), S.end());
        dfs(S, ret, mid, 0, S.size());
        return ret;
    }
};

int main()
{
    vector<int> S(3, 0);
    Solution a;
    for(int i = 0; i < 3; i++)
        S[i] = i + 1;
    a.subsets(S);
    cout << "Hello world!" << endl;
    return 0;
}
