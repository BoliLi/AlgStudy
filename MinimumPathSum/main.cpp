#include <iostream>
#include <vector>
/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which
minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.*/
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        f[0][0] = grid[0][0];
        for(int i = 1; i < m; i++)
            f[i][0] = f[i - 1][0] + grid[i][0];
        for(int i = 1; i < n; i++)
            f[0][i] = f[0][i - 1] + grid[0][i];
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(f[i - 1][j] < f[i][j - 1])
                    f[i][j] = f[i - 1][j] + grid[i][j];
                else
                    f[i][j] = f[i][j - 1] + grid[i][j];
            }
        }
        return f[m - 1][n - 1];
    }
};

int main()
{
    vector<vector<int>> grid(4, vector<int>(4, 5));
    Solution a;

    grid[0][1] = 2;
    grid[1][0] = 3;
    grid[2][0] = 3;

    cout << a.minPathSum(grid) << endl;
    return 0;
}
