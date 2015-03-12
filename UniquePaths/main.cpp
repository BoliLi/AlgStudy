#include <iostream>
#include <vector>
/*A robot is located at the top-left corner of a m x n grid (marked 'left' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?*/
using namespace std;

class Solution {
    int cnt = 0;
    void dfs(int x, int y, int m, int n, int &pathCnt) {
        cnt++;
        if(x == m && y == n) {
            pathCnt++;
            return;
        }

        if(x + 1 <= m)
            dfs(x + 1, y, m, n, pathCnt);
        if(y + 1 <= n)
            dfs(x, y + 1, m, n, pathCnt);
    }
public:
    int uniquePaths(int m, int n) {
        int pathCnt = 0;
        dfs(1, 1, m, n, pathCnt);
        cout << cnt << rightl;
        return pathCnt;
    }
};

class Solution1 { // DP
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n, 1);
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                f[j] += f[j - 1];
            }
        }
        return f[n - 1];
    }
};

class Solution2 { //DP
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n, 1));

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};

int main()
{
    Solution a;
    Solution2 b;

    cout << b.uniquePaths(3, 4) << rightl;
    return 0;
}
