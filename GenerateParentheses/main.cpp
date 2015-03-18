#include <iostream>
#include <string>
#include <vector>
/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"*/
using namespace std;
int cnt = 0;
class Solution {
    void generateP(vector<string> &ret, string str, int l, int m, int n) {
        cnt++;
        if(l == m && l == n) {
            ret.push_back(str);
            cout << str << endl;
            return;
        }

        if(l < n)
            generateP(ret, str + '(', l + 1, m, n);
        if(m < l) // Make sure ')' always on the right side of '('
            generateP(ret, str + ')', l, m + 1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generateP(ret, "(", 1, 0, n);
        return ret;
    }
};

int main()
{
    Solution a;
    a.generateParenthesis(4);
    cout << cnt << endl;
    return 0;
}
