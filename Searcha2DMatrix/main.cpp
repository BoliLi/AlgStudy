#include <iostream>
#include <vector>
/*Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.*/
using namespace std;

int bSearch(int arr[], int begin, int end, int target)
{
    int mid, left = begin, right = end;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(arr[mid] == target)
            return mid;
        if(arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left; //Not found, return the closest on the RIGHT
    //return right; //Not found, return the closest on the LEFT
}

class Solution {

public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int col = matrix[0].size();
        int row = matrix.size();
        int left, right, mid, midRet;

        left = 0;
        right = row - 1;
        while(left <= right) {
            mid = (left + right) / 2;
            if(matrix[mid][0] == target) {
                return true;
            } else if(matrix[mid][0] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        midRet = right;

        left = 0;
        right = col - 1;
        while(left <= right) {
            mid = (left + right) / 2;
            if(matrix[midRet][mid] == target)
                return true;
            else if(matrix[midRet][mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        cout << midRet << " " << left << endl;
        return false;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> f(4, vector<int>(4, 1));
    int arr[10] = {0};
    int cnt = 1;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            f[i][j] = cnt;
            cnt += 3;
        }
    }
    cnt = 1;
    for(int i = 0; i < 10; i++) {
        arr[i] = cnt;
        cnt += 3;
    }

    cout << a.searchMatrix(f, 10) << endl;
    cout << bSearch(arr, 0, 9, 7) << endl;
    return 0;
}
