#include <iostream>
#include <vector>
#include <algorithm>
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

class Solution { // Wrong!!
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

class Solution1 {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> path;
        dfs(n, k, 1, 0, path, result);
        return result;
    }
private:
    // start，开始的数, cur，已经选择的数目
    static void dfs(int n, int k, int start, int cur,
        vector<int> &path, vector<vector<int> > &result) {
        if (cur == k) {
            for(int j = 0; j < path.size(); j++)
                cout << path[j] << " ";
            cout << endl;
            result.push_back(path);
        }
        for (int i = start; i <= n; ++i) {
            path.push_back(i);
            dfs(n, k, i + 1, cur + 1, path, result);
            path.pop_back();
        }
    }
};

bool cmp(int a, int b) {
    return a < b;
}

int main()
{
    Solution1 a;
    vector<int> vec(5, 0);
    vec[0] = 4;
    vec[1] = 5;
    vec[2] = 2;
    vec[3] = 7;
    vec[4] = 1;
    sort(vec.begin(), vec.end(), cmp);
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
    a.combine(5, 3);
    cout << "Hello world!" << endl;
    return 0;
}
