#include <iostream>
#include <vector>
/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?*/
using namespace std;
//Project 0 to the edge of the matrix
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool row_flag = false;
        bool col_flag = false;
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0; i < row; i++) {
            if(matrix[i][0] == 0) {
                col_flag = true;
                break;
            }
        }

        for(int i = 0; i < col; i++) {
            if(matrix[0][i] == 0) {
                row_flag = true;
                break;
            }
        }

        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i < row; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < col; j++)
                    matrix[i][j] = 0;
            }
        }

        for(int j = 1; j < col; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < row; i++)
                    matrix[i][j] = 0;
            }
        }

        if(row_flag) {

        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
