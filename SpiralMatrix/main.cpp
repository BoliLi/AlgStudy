#include <iostream>
#include <vector>
/*Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].*/
using namespace std;
//Ä£Äâ
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int leftX = 0;
        int rightX = matrix.size() - 1;
        int topY = 0;
        int bottomY = matrix.size() - 1;
        vector<int> ret;

        while(1) {
            for(int i = leftX; i <= rightX; i++)
                cout << matrix[topY][i] << " ";
            if(++topY > bottomY)
                break;
            for(int i = topY; i <= bottomY; i++)
                cout << matrix[i][rightX] << " ";
            if(--rightX < leftX)
                break;
            for(int i = rightX; i >= leftX; i--)
                cout << matrix[bottomY][i] << " ";
            if(--bottomY < topY)
                break;
            for(int i = bottomY; i >= topY; i--)
                cout << matrix[i][leftX] << " ";
            if(++leftX > rightX)
                break;
        }
        return ret;
    }
};

int main()
{
    int n = 3;
    vector<vector<int> > matrix;
    Solution a;

    matrix.resize(n);
    for(int i = 0; i < n; i++)
        matrix[i].resize(n);
    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrix[i][j] = ++k;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    a.spiralOrder(matrix);
    cout << "Hello world!" << endl;
    return 0;
}
