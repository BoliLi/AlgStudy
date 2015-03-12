#include <iostream>
/*You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?*/
using namespace std;
//先横中线，后斜线为轴对调
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n / 2; j++) {
                swap(matrix[j][i], matrix[n - j - 1][i]);
            }
        }

        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
