#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <string.h>

using namespace std;
//midRes[i]表示第i行的Q所在的位置
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        int *midRes = new int[n];
        vector<vector<string> > ret;
        for(int i = 0; i < n; i++)
            midRes[i] = 0x7FFFFFF;
        dfs(ret, midRes, n, 0);
        delete[] midRes;
        return ret;
    }
private:
    vector<string> buildMap(int n) {
        vector<string> ret;
        for(int i = 0; i < n; i++) {
            string str = string(n, '.');
            ret.push_back(str);
        }
        return ret;
    }

    int isValid(int midRes[], int curX, int curY, int n) {
        for(int i = 0; i < curY; i++) {
            if(midRes[i] == curX)
                return 0;
        }
        return 1;
    }

    void dfs(vector<vector<string> > &ret, int midRes[], int n, int curY) {
        if(curY == n) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(midRes[i] == j)
                        cout << "Q ";
                    else
                        cout << ". ";
                }
                cout << endl;
            }
            cout << "-------------------" << endl;
            return;
        }

        for(int i = 0; i < n; i++) {
            if(isValid(midRes, i, curY, n)) {
                midRes[curY] = i;
                dfs(ret, midRes, n, curY + 1);
            }
        }

    }
};

int main()
{
    Solution a;
    a.solveNQueens(4);
    cout << "Hello world!" << endl;
    return 0;
}
