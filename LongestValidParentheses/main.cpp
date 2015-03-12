#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> stk;
        int ret = 0;
        int max = 0;
        int i;

        for(i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                max++;
                stk.push('(');
            } else {
                if(stk.empty())
                    continue;
                if(stk.top() != '(') {
                    if(max > ret)
                        ret = max;
                    while(!stk.empty())
                        stk.pop();
                    max = 0;
                } else {
                    max++;
                    stk.pop();
                }
            }
        }
        if(max > ret)
            ret = max;
        return ret;
    }
};

int main()
{
    Solution a;

    cout << a.longestValidParentheses(")())") << endl;
    return 0;
}
