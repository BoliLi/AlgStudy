#include <iostream>
#include <vector>
/*Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.*/
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            if(obstacleGrid[i][0] != 1)
                f[i][0] = 1;
            else
                break;
        }

        for(int i = 0; i < n; i++) {
            if(obstacleGrid[0][i] != 1)
                f[0][i] = 1;
            else
                break;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i - 1][j] == 1 || f[i - 1][j] == 0)
                    f[i][j] = f[i][j - 1];
                else if(obstacleGrid[i][j - 1] == 1 || f[i][j - 1] == 0)
                    f[i][j] = f[i - 1][j];
                else
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};

int main()
{
    vector<vector<int>> obstacleGrid(4, vector<int>(4, 0));
    Solution a;

    obstacleGrid[0][2] = 1;
    cout << a.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
