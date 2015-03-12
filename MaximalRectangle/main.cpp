#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
/*Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones
and return its area.*/
using namespace std;
//Convert each row into histogram and find the largest rectangle in histogram
class Solution {
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        height.push_back(0);
        int result = 0;
        int i = 0;
        while(i < height.size()) {
            if(s.empty() || height[i] > height[s.top()])
                s.push(i++);
            else {
                int tmp = s.top();
                int curRes = 0;
                s.pop();
                curRes = height[tmp] * (s.empty() ? i : i - s.top() - 1);
                result = max(result, curRes);
            }
        }
        return result;
    }
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ret = 0;
        vector<vector<int> > rectMatrix(m, vector<int>(n, 0));

        /* Convert each row into histogram */
        for(int i = 0; i < n; i++)
            rectMatrix[0][i] = matrix[0][i];

        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1)
                    rectMatrix[i][j] = rectMatrix[i - 1][j] + 1;
            }
        }

        for(int i = 0; i < m; i++)
            ret = max(ret, largestRectangleArea(rectMatrix[i]));
        return ret;
    }
};

int main()
{
    vector<vector<char> > matrix(6, vector<char>(6, 0));
    Solution a;

    for(int i = 2; i < 4; i++) {
        for(int j = 3; j < 5; j++)
            matrix[i][j] = 1;
    }

    matrix[1][3] = 1;
    matrix[5][3] = 1;
    //matrix[4][3] = 1;
    matrix[5][2] = 1;
    cout << a.maximalRectangle(matrix) << endl;
    return 0;
}
