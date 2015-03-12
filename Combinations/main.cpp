#include <iostream>
#include <vector>
/*Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]*/
using namespace std;

class Solution {
    void dfs(vector<vector<int> > &ret, vector<int> &mid, int n, int curP, int curK) {
        if(curK == 1) {
            for(int i = curP + 1; i < n; i++) {
                mid.push_back(i);
                ret.push_back(mid);
                for(int j = 0; j < mid.size(); j++)
                    cout << mid[j] << " ";
                cout << endl;
                mid.pop_back();
            }
            return;
        }

        if(n - curP < curK)
            return;

        for(int i = curP; i < n; i++) {
            mid.push_back(i);
            dfs(ret, mid, n, i, curK - 1);
            mid.pop_back();
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> mid;

        dfs(ret, mid, n, 0, k);
        return ret;
    }
};

int main()
{
    Solution a;
    a.combine(4, 3);
    cout << "Hello world!" << endl;
    return 0;
}
